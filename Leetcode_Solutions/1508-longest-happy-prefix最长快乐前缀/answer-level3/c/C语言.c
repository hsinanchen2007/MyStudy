用memcmp就可以，用自己写的那段就超时，有大神了解原因的告诉一下我
```
char * longestPrefix(char * s){
    int end=strlen(s)-1;
    int start=end-1;
    char *ret=malloc(100000);
    int find=0;
    int len=strlen(s)-1;
    while(start>=0){
        if(s[start]!=s[end])start--;
        else{
            // int i=0;
            // int j=len-start;
            //  while(i<=start&&s[i]==s[j]){
            //     i++;
            //     j++;
            // }if(i==start+1)
            if(!memcmp(s,s+len-start,start+1))
            {
                find=1;
                memcpy(ret,s,start+1);
                ret[start+1]='\0';
                break;
            }else start--;
        }
    }
    if(find)return ret;
    else return "";
}
```
