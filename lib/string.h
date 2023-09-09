// Copyright 2023 Peregrin

#ifndef STRING_H_
#define STRING_H_

#ifndef size_t
typedef unsigned long size_t;
#endif

size_t slen(char*);
int scmp(char* , char*);
int scon(char* , char*); 
int sdel(char* , char*);

#endif
