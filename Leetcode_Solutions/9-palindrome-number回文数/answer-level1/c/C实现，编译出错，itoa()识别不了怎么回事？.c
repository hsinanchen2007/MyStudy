#include <stdio.h>
#include <stdlib.h>
bool isPalindrome(int x){
char *str;
int i,j;
int len=strlen(str);
itoa(x,str,10);
for(i=0; i<len/2; i++){
    for(j=len; j>len/2; j--){
        if(str[i]==str[j]){
            return true;
        }
        else
        return false;
    }
}
}