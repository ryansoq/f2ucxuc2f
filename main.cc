#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <string>
#include <sstream>
#include <iomanip>

void float2uchar(float *target, unsigned char *ptr, int size)
{
    assert(size == 4); //Currently, only supports one value.
    memcpy(ptr, target, size);
}

void uchar2float(unsigned char *target, float *ptr, int size)
{
    assert(size == 4);
    memcpy(ptr, target, size);
}

void uchar2string(unsigned char *target, std::string *ptr, int size)
{
    assert(size == 4);
    std::stringstream ss;
    for (auto i = 0; i < size; i++)
        ss << std::setw(2) << std::setfill('0') << std::hex << (0xFF & target[i]);
    *ptr = ss.str();
}

int TRANS(unsigned char val)
{
    if (val >= 'a' && val <= 'f')
        return val - 87;
    else if (val >= 'A' && val <= 'F')
        return val - 55;
    else if (val >= '0' && val <= '9')
        return val - 48;
    else
        assert(0);
}

void string2float(std::string target, float *ptr, int size)
{
    assert(size == 4);
    unsigned char s2uc[4] = {0};

    for (auto i = 0; i < size; i++)
    {
        int a = TRANS(((unsigned char *)target.c_str())[2 * i + 0]);
        int b = TRANS(((unsigned char *)target.c_str())[2 * i + 1]);
        s2uc[i] = 0;
        s2uc[i] = s2uc[i] + a << 4;
        s2uc[i] = s2uc[i] | b;
    }

    uchar2float(s2uc, ptr, sizeof(s2uc));
}

int main()
{
    unsigned char uchar[4] = {0};
    float f = 3.14159265358979323846;

    printf("Before uc2f : %0.16f \n", f);

    // float to unsigned char
    float2uchar(&f, uchar, sizeof(float));

    for (auto i = 0; i < sizeof(float); i++)
        printf("0x%02x ", uchar[i]);
    printf("\n");

    f = 0.f;

    uchar2float(uchar, &f, sizeof(float));

    printf("After uc2f : %0.16f \n", f);

    std::string s_test;
    float f_test;

    uchar2string(uchar, &s_test, sizeof(float));
    printf("s_test : %s \n", s_test.c_str());

    string2float("db0f4940", &f_test, sizeof(float));
    printf("f_test : %0.16f \n", f_test);

    return 0;
}
