```c
int strStr(char * haystack, char * needle){
    short len_haystack=0,len_needle=0,i,j;
    while(haystack[len_haystack]!=0) len_haystack++;
    while(needle[len_needle]!=0) len_needle++;
    if(len_needle==0) return 0;
    for(i=0;i<len_haystack;i++){
        if(haystack[i]==needle[0]){
            for(j=0;j<len_needle;j++){
                if(haystack[i+j]==0) break;
                if(haystack[i+j]!=needle[j]) break;
            }   
            if(j==len_needle) return i;
        }
    }
    if(i==len_haystack) return -1;
    return 0;
}
```