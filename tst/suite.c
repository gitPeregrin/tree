#include "../lib/string.h"
#include "../lib/colors.h"

int puts(const char*);
int printf(const char*,...);

#ifndef free
void free(void*);
#endif

int main(void) /*testing suite*/ {

   {//testing slen
      char str[] = "Hello, world!";
      size_t len = sizeof(str)-1;
      
      size_t res = slen(str);

      if (len^res) {
         puts(strRED "FAILED" strDEF ": slen() for char[]");
         printf(strRED "%lu != %lu\n" strDEF , len , res);
         return 1;
      } else {
         puts(strGREEN "OK" strDEF ": slen() for char[]");
      };
   };

   {//testing slen
      char* str = "hello";
      size_t len = 5;

      size_t res = slen(str);

      if (len^res) {
         puts(strRED "FAILED" strDEF ": slen() for char*");
         printf(strRED "%lu != %lu\n" strDEF , len , res);
         return 1;
      } else {
         puts(strGREEN "OK" strDEF ": slen() for char*");
      };
   };

   {//testing scmp
      char str1[] = "Hello";
      char* str2 = "world!"; 

      int res1 = (int) scmp(str1, str2);           // 0 NOT compare
      int res2 = 1 - (int) scmp(str1, "Hello");    // 1 compare
      int res3 = 1 - (int) scmp("world!", str2);   // 1 compare
      int res4 = (int) scmp(str2, str1);           // 0 NOT compare

      if (res1 & res2 & res3 & res4) {
         puts(strRED "FAILED" strDEF ": scmp");
         printf(strRED "res1: %d\n" strDEF, res1);
         printf(strRED "res2: %d\n" strDEF, res2);
         printf(strRED "res3: %d\n" strDEF, res3);
         printf(strRED "res4: %d\n" strDEF, res4);
         return 1;
      } else {
         puts(strGREEN "OK" strDEF ": scmp");
      };
   };

   {//testing scon
      char str[15] = "Hello";
      char* substr = ", wordl!";

      char result[15] = {0}; 
      scon(str,substr);
      scon(result,str); 

      if (!scmp(str,result)) {
         puts(strRED "FAILED" strDEF ": scon() for char[] + char*");
         printf(strRED "%s != %s\n" strDEF , str , result);
         return 1;
      } else {
         puts(strGREEN "OK" strDEF ": scon() for char[] + char*");
      };
   };

   {//testing scon
      char str[15] = "Hello";
      char substr[] = ", wordl!";

      char result[15] = {0};
      scon(str,substr);
      scon(result,str);

      if (!scmp(str,result)) {
         puts(strRED "FAILED" strDEF ": scon() for char[] + char[]");
         printf(strRED "%s != %s\n" strDEF , str , result);
         return 1;
      } else {
         puts(strGREEN "OK" strDEF ": scon() for char[] + char[]");
      };
   };

   {//testing sdel
      char* result = "Hello";   

      char str[] = "Hello/annie";
      sdel(str, "/annie");

      if (!scmp(str,result)) {
         puts(strRED "FAILED" strDEF ": scut()");
         printf(strRED "%s != %s\n" strDEF , str , result);
         return 1;
      } else {
         puts(strGREEN "OK" strDEF ": scut()");
      };
   };


   return 0;
}
