# float2uchar

## Building

```
./make.sh
```
## Run

```
int main()
{
    unsigned char uchar[4] = {0};
    float f = 3.14159265358979323846;

    printf("Current f value : %0.16f \n", f);

    // float to unsigned char
    float2uchar(&f, uchar, sizeof(float));

    for (auto i = 0; i < sizeof(float); i++)
        printf("0x%02x ", uchar[i]);
    printf("\n");

    // Set f is 0.f
    f = 0.f;
    printf("Set f value to 0.f \n");
    printf("Before uc2f, f value : %0.16f \n", f);

    // Get value from uchar
    uchar2float(uchar, &f, sizeof(float));

    printf("After uc2f, f value : %0.16f \n", f);

    std::string s_test;
    float f_test;

    // unsigend char to string
    uchar2string(uchar, &s_test, sizeof(float));
    printf("s_test : %s \n", s_test.c_str());

    // string to float
    string2float("db0f4940", &f_test, sizeof(float));
    printf("f_test : %0.16f \n", f_test);

    return 0;
}
/* -----------------------------------
Current f value : 3.1415927410125732
0xdb 0x0f 0x49 0x40
Set f value to 0.f
Before uc2f, f value : 0.0000000000000000
After uc2f, f value : 3.1415927410125732
s_test : db0f4940
f_test : 3.1415927410125732
----------------------------------- */
```
