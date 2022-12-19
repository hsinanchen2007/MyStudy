### 解题思路
此处撰写解题思路

### 代码

```c
bool isValid(char * s){
    int len=strlen(s);
    int i;
struct node{
    char str[len];
    int top;
};
struct node stack;
stack.top=-1;
for(i=0;i<=len-1;i++){
    
    /*if(stack.top==-1&&(s[i]=='('||s[i]=='['||s[i]=='{')){
        stack.str[++stack.top]=s[i];
    }else if(stack.top!=-1){
        */stack.str[++stack.top]=s[i];
   // }
if(stack.top!=-1&&stack.top!=0&&(stack.str[stack.top]==stack.str[stack.top-1]+1||stack.str[stack.top]==stack.str[stack.top-1]+2)){
    stack.top=stack.top-2;
}
}
if(stack.top==-1){
    return true;
}else{
    return false;
}

}
```