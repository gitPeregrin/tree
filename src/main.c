
#include <locale.h>
#include <dirent.h>
#include "../lib/colors.h"
#include "../lib/string.h"

int sprintf(char*, const char*, ...);
int printf(const char*, ...);
void free(void*);

int main1(int argc, const char* argv[]){
   for(int i=0; i<argc; i++)
      printf("argc: %d -> argv: %s\n",
         i, argv[i]);
   return 0;
}



void print_tree(char* path){
   #define name line->d_name
   static int level = 0;
   char buf[1024] = {0};
   char tmp[1024] = {0};
   DIR* dir;
   struct dirent* line;
   

   scon(buf,path); //add to buf path
//printf("buf: %s\n", buf); // TODO
   dir = opendir(buf);
   
   scon(tmp,buf);
   while((line=readdir(dir))){      

      scon(tmp,"/");
      scon(tmp,name);

//printf("tmp:%s\n",tmp); // TODO debug info

      if( scmp(".",name)
         || scmp("..",name)
         || scmp(".DS_Store",name) ) {
         sdel(tmp,name);
         sdel(tmp,"/");
         continue;
      };

      for(int i=0; i<level; i++)
         (i+1==level)?
         printf(strWIDE "┗╍► " strDEF) :
         printf(strWIDE "┃   " strDEF);

      if(opendir(tmp)!=NULL){ // if name = dir

         printf(strGREEN "%s\n" strDEF, name);
         level++;
         print_tree(tmp);

      }else{                  // if name = file

         printf(strDEF "%s\n" strDEF, name);

      };

      sdel(tmp,name);
      sdel(tmp,"/");

   };
   level--;

   #undef name
}

int main(int argc, const char* argv[])
{
   setlocale(LC_ALL,"Ru");

   print_tree("."); 
   return(0);
};
