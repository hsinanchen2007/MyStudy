### 解题思路
此处撰写解题思路
1 step 申请一个字符串长度的空间;
2 step 普通的进栈退栈;
3 step 不需一个特别的判空栈的方案,因为栈是从top=1 开始存入的;
4 step  return p+1;

### 代码

```c
char * removeDuplicates(char * S){
char *p;
int n,top=0,i=0;
n=strlen(S);
p=(char *)malloc(sizeof(char)*n);
// 每次为空栈时下一次必存入;
while(S[i]!='\0')
{
     // 相等时就退栈;
       if(p[top]==S[i])
             top--;
       // 不相等时就进栈;
       else if(p[top]!=S[i] )
       {
            top++;
            p[top]=S[i];
       }
       i++;
}
 // 添加终止符;
 p[top+1]='\0';
 return p+1;
}
```