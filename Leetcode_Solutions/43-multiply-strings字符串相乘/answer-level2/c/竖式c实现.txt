### 解题思路
不断地更新竖式的结果

### 代码

```c
char * multiply(char * num1, char * num2){
int flag=0,p=0,q=0,m=220;
int size1 = strlen(num1),size2 = strlen(num2);
char *n1=malloc(sizeof(char)*110);
char *n2=malloc(sizeof(char)*110);
char *temp=malloc(sizeof(char)*250);
char *res=malloc(sizeof(char)*200);
strcpy(n1, num1);
strcpy(n2, num2);
for(int i=0;i<=220;i++)
temp[i]='0';
for(int i=strlen(n2)-1;i>=0;i--)
{
    for(int j=strlen(n1)-1;j>=0;j--)
    {
        if(i==strlen(n2)-1)
        {int tp1 = n1[j]-'0';
        int tp2 = n2[i]-'0';
        if((tp1*tp2)%10+flag<10)
        {
		temp[m]=(tp1*tp2)%10+flag+'0';
        flag = (tp1*tp2)/10;
        m--;
		}
		else
		{
		temp[m]=((tp1*tp2)%10+flag)%10+'0';
        flag = (tp1*tp2)/10+((tp1*tp2)%10+flag)/10;
        m--;	
		}}
        else
        {
        int tp1 = n1[j]-'0';
        int tp2 = n2[i]-'0';
        int tp = temp[m]-'0';
        if(tp+(tp1*tp2)%10+flag<10)
        {temp[m]=tp+(tp1*tp2)%10+flag+'0';
        flag = (tp1*tp2)/10;
        m--;}
        else
        {
        temp[m]=(tp+(tp1*tp2)%10+flag)%10+'0';
        flag = (tp1*tp2)/10+(tp+(tp1*tp2)%10+flag)/10;
        m--;
        }
        }
    }
    if(flag!=0)
    {temp[m]=flag+'0';
flag=0;
    }
    if(i!=0)
    m=220-(strlen(n2)-i);
}
if(flag!=0)
temp[m]=flag+'0';
while(temp[m]=='0')
{m++;}
p=0;
if(m>220)
m=220;
for(int i = m;i<=220;i++)
{
    res[p]=temp[i];
    p++;
}
res[p]='\0';
return res;
}
```