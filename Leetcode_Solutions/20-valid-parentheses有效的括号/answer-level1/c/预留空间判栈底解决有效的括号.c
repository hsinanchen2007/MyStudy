### 解题思路
此处撰写解题思路
1 step strlen(s) 求出*s 的长度,并申请一个n+1 个空间的；
2 step 预留一个空间，判段是否为到栈底，防止为top=负数的情况;
3 step 判段是否为原栈底,
### 代码

```c
bool isValid(char * s){
char *str;
int  i=0, n;
long int top=0;
n=strlen(s);
str=(char *)malloc(sizeof(char)*(n+1));
// 预留一个判空;
str[0]='a';
while(s[i]!='\0') //退出的条件;
{
       // 左括号进栈;
        if(s[i]=='(' || s[i]=='{' || s[i]=='[' )
        {
               top++;
               str[top]=s[i]; 
        }
        else
        {
                            
                 //判段不退栈的条件;
                  if(s[i]==')'&&(str[top]=='{' || str[top]=='[' ||str[top]=='a' ) )
                  return false;
                  else if(s[i]=='}' &&  (str[top]=='[' || str[top]=='(' || str[top]=='a')  )
                   return false;
                  else  if(s[i]==']' && ( str[top]== '{' || str[top]=='('|| str[top]=='a' )  )
                  return false;
                  // 上述的情况都不满足时就执行退栈操作;
                  top--;
        }
        i++;
}
   if(top!=0) 
   return false;
   else
   return true;
}
```