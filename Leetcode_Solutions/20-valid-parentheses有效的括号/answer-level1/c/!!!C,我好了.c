### 解题思路
此处撰写解题思路

### 代码

```c
bool isValid(char * s){
    int i,top=-1;
    char *stack=NULL;
    stack=(char *)malloc(strlen(s));
    if(s){
        for(i=0;s[i]!='\0';i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['||top==-1)
            stack[++top]=s[i];
            else if(s[i]==stack[top]+1||s[i]==stack[top]+2)
            top--;
            else break;
        }
    }
    if(top>-1) return false;
    else return true;
}
```