### 解题思路
原地处理之后会考虑一下

### 代码

```c


char * reverseWords(char * s){
    if(strlen(s)==0) return s;
    char *res=(char *)malloc(sizeof(char)*(strlen(s)+1));
    int index=0;
    int p;
    for(int i=strlen(s)-1;i>=0;i--){
        if(s[i]!=' '){
            p=i;
            while(p>=0&&s[p]!=' ')    p--;
            for(int j=p+1;j<=i;j++)
                res[index++]=s[j];
            res[index++]=' ';
            i=p;
            
        }
    }
    if(index==0) return "";
    res[index-1]='\0';
    return res;
                             
}


```