### 解题思路
此处撰写解题思路
1 step 判是否为原语,记录每一次判段原语循环开始前的位置,和循环结束的位置，由两者的关系存入;
2 step 存入去括号部份;
3 为添加终止符;

### 代码

```c
char * removeOuterParentheses(char * S){
 int i=0,j=0,idex,top=0 ,k=0;
// int n;
 char *p;
//n=strlen(S);
 //p=(char *)malloc(sizeof(char) *n) ;
 while(1)
 {
        idex=i;
        while(1)
        {
              if(S[i]=='(')
              top++;
              else
              top--;
              if(top==0)
              break;
              i++;
        }
        for(j=idex+1 ;j<i;j++)
        {
               S[k]=S[j];
               k++;
        }
        i++;
        if(S[i]=='\0')
        break;

 }
 S[k]='\0';
 return S;
}
