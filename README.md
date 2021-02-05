# float2uchar

## Building

```
./make.sh
```
## Run

```
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
//-----------------
result :
Before uc2f : 3.1415927410125732
0xdb 0x0f 0x49 0x40
After uc2f : 3.1415927410125732
s_test : db0f4940
f_test : 3.1415927410125732
//-----------------
```
