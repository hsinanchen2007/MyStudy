### 解题思路
创建字符数组模拟栈

### 代码

```c
bool isValid(char * s){
    int len=strlen(s);
    char *a=malloc(sizeof(char)*len);
    int i,j=-1;
    for(i=0;i<len;i++)
    {
        if(s[i]=='('||s[i]=='['||s[i]=='{')
        {
            a[++j]=s[i];
        }
        else if(s[i]==')'||s[i]==']'||s[i]=='}')
        {
            if(j==-1)return false;
            else
            {
                if((s[i]==')' && a[j]=='(')) j--;
                else if(s[i]==']' && a[j]=='[')  j--;
                else if(s[i]=='}' && a[j]=='{') j--;
                else 
                    return false;
            }      
        }
    }
    if(j==-1)return true;
    else {
         return false;
    }

}
```