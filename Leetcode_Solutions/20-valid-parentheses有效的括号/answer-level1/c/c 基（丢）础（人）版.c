### 解题思路
此处撰写解题思路

### 代码

```c
bool isValid(char * s){
    int i,j;
    char *p=s,*str=NULL;
    if(*p=='\0') return true;
    if(*p!='('&&*p!='['&&*p!='{')  return false;
    j=strlen(s);
    str=(char *)malloc(j);
    memset(str,'\0',j);
    for(i=0;*p!='\0';){
        if(*p=='('||*p=='['||*p=='{'||*p!='\0')
        switch(*p){
            case '(':str[i++]=*p++;break;
            case '{':str[i++]=*p++;break;
            case '[':str[i++]=*p++;break;
        }
        if(*(p)!='('&&*(p)!='['&&*(p)!='{'&&*(p)!='\0'){
            if(i==0) return false;
            switch(*p){
            case ')':{
                if((str[i-1])=='('){
                    str[--i]='\0';p++;break;
                }
                else str[i++]=*p++;break;
            }
            case '}':{
                if((str[i-1])=='{'){
                    str[--i]='\0';p++;break;
                }
                else str[i++]=*p++;break;
            }
            case ']': {
                if((str[i-1])=='['){
                    str[--i]='\0';p++;break;
                }
                else str[i++]=*p++;break;
            }
            }
        }

    }
    if(*str=='\0') {
        free(str);
        return true;
    }
    else{
       free(str); 
        return false;
    }
}
```