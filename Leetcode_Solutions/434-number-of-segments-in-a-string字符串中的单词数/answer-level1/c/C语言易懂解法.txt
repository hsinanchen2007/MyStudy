### 解题思路
依次遍历，如果出现空格将情况分为连续空格和非连续空格情况。注意字符串是否以空格结束。

### 代码

```c
int pd(char c)
{
    if(c==' ')
    return 1;
    else return 0; 
}

int countSegments(char * s){
   int len=strlen(s);
   int flag=1;
   int count=0;
   int i=0;
   while(pd(s[i]))i++;
   for(int j=i;j<len;j++)
   {
       if(pd(s[j]))
       {
           if(flag==0)
           {
               flag=1;
               count++;
           }
       }
      else{
          flag=0;
      }
   }
  if(flag==0)count++;
  return count;
}
```