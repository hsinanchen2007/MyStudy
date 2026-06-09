### 解题思路
此处撰写解题思路

### 代码

```c
char Change(char c)
{
    switch(c){
        case '}':return '{';break;
        case ')':return '(';break;
        case ']':return '[';break;
    }
    return;
}
bool isValid(char * s){
int n=strlen(s),i=0,j=-1;
char c;
char*str=(char*)malloc(sizeof(char)*n);
while(i<n){
    if(s[i]=='('||s[i]=='{'||s[i]=='[')
    str[++j]=s[i++];
    else if(j==-1&&(s[i]==')'||s[i]=='}'||s[i]==']'))
    return false;
    else{
        c=Change(s[i]);
        if(str[j]==c)
         {j--;i++;}
        else
        break;
    }
}
if(j>=0)       //栈内的元素未匹配完
return false;
else
return true;
}
```