### 解题思路
用数组来模拟栈的过程

### 代码

```c
bool isValid(char * s){
    int len=strlen(s);
    char *a=malloc(sizeof(char)*2*len);
    int j=len;
    for(int i=0;i<len;i++){
        if(s[i]=='(')
            a[j++]=s[i];
        else if(s[i]=='{')
            a[j++]=s[i];
        else if(s[i]=='[')
            a[j++]=s[i];
        else if(s[i]==')'){
            if(a[j-1]=='(')
                j--;
             else
                return false;
        }
        else if(s[i]=='}'){
            if(a[j-1]=='{')
                j--;
            else
                return false;
        }
        else{
            if(a[j-1]=='[')
                j--;
             else
                return false;
        } 
    }
    if(j==len)
        return true;
    return false;
}
```