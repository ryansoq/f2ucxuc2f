#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iomanip>

void float2uc(float * target, unsigned char * ptr, int size)
{
    memcpy(ptr, target, size);
}

void uc2float(unsigned char * target, float * ptr, int size)
{
    memcpy(ptr, target, size);
}

void uc2string(unsigned char * target, std::string * ptr, int size)
{
    std::stringstream ss;
    for (auto i = 0; i < size; i++)
        ss << std::setw(2) << std::setfill('0') << std::hex << (0xFF & target[i]);
    *ptr = ss.str();
}

int TRANS(unsigned char val)
{
   if (val >= 'a')
      return val - 87;
   else if (val >= 'A')
      return val - 55;
   else if (val >= '0')
      return val - 48;
}

void st2float(std::string target, float * ptr, int size)
{
    unsigned char f2uc[4] = {0};

    for (auto i = 0; i < size; i++)
    {
        int a = TRANS( ((unsigned char*)target.c_str())[2 * i + 0] );
        int b = TRANS( ((unsigned char*)target.c_str())[2 * i + 1] );
        f2uc[i] = 0;
        f2uc[i] = f2uc[i] + a << 4;
        f2uc[i] = f2uc[i] | b;
    }

    uc2float(f2uc, ptr, sizeof(f2uc));
}

int main()
{
   unsigned char f2uc[4] = {0};
   float uc2f = 3.14159265358979323846;

   printf("Before uc2f : %0.16f \n", uc2f);
   float2uc(&uc2f, f2uc, sizeof(float));

   for (auto i = 0; i < sizeof(float); i++)
       printf("0x%02x ", f2uc[i]);
   printf("\n");

   uc2f = 0.f;
   uc2float(f2uc, &uc2f, sizeof(float));

   printf("After uc2f : %0.16f \n", uc2f);

   std::string s_test;
   float f_test;

   uc2string(f2uc, &s_test, sizeof(f2uc));
   printf("s_test : %s \n", s_test.c_str());

   st2float("db0f4940", &f_test, sizeof(f2uc));
   printf("f_test : %0.16f \n", f_test);

   return 0;
}
