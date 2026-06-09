### 解题思路
从后往前转换时关键

### 代码

```c
char * freqAlphabets(char * s){
    char *res;
    int count=0;
    int i;
    int k=0;
    int len;
    len=strlen(s);
    i=len-1;
    while(i>=0){
        if(s[i]=='#'){
            s[i-2]=(s[i-2]-'0')*10+s[i-1]-'0'+'a'-1;
            i=i-3;
        }
        else{
            s[i]=s[i]-'0'+'a'-1;
            i=i-1;
        }
        count++;
    }
    res=(char *)malloc(sizeof(int)*(count+1));
    i=0;
    while(i<len){
        if(s[i]>='a'&&s[i]<='z'){
            res[k++]=s[i];
        }
        i++;
    }
    res[count]='\0';
    return res;
}
```