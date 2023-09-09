// Copyright 2023 Peregrin

#ifndef size_t
typedef unsigned long size_t;
#endif
#ifndef malloc
void* malloc(size_t);
#endif
#ifndef sprintf
int sprintf(char *buf, const char *format, ...);
#endif

//debug only
int puts(const char* string);
int printf(const char* format, ...);

size_t slen(char* str){
   size_t i = 0;
   while(str[i]) i++;
   return i;
}

int scmp(char* str1, char* str2){
   size_t i = 0;
   while(str1[i]){
      if(str1[i]^str2[i]) return 0; // NOT compare   
      i++;
   }
   return 1; // compare  
}

int scon(char* str, char* substr) {
   size_t p = 0;
   p = slen(str);
   return sprintf(&str[p], "%s", substr);
};

int sdel(char* str, char* substr) {
   size_t ptr = slen(str) - slen(substr);
   return str[ptr] = 0;
};
