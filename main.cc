#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void float2uc(float * target, unsigned char *ptr, int size)
{
    memcpy(ptr, target, size);
}

void uc2float(unsigned char *target, float * ptr, int size)
{
    memcpy(ptr, target, size);
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

   return 0;
}