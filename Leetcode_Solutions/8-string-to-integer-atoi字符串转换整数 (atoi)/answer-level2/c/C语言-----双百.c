### 解题思路
此处撰写解题思路

### 代码

```c
int myAtoi(char * str){
int i=0,flag=1,s=1,m;
long int sum=0;
m=strlen(str);
while(i<m)
{
    if(str[i]=='-'&&flag)
    {
        s=-1;flag=0;i++;
    }
    else if(str[i]>='0'&&str[i]<='9')
    {
        sum=sum*10;
        sum+=str[i]-'0';
        i++;
        flag=0;
        if(sum>2147483647)
        break;
    }
    else if(str[i]==' '&&flag)
    i++;
    else if(str[i]=='+'&&flag)
    {s=1;flag=0;i++;}
    else 
    break;
}
if(sum>2147483647)
return (s>0?INT_MAX:INT_MIN);
else
return sum*s;
}
```