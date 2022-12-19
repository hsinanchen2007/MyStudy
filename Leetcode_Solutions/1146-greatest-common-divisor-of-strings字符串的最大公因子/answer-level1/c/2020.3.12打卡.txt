### 解题思路
最大公因子串的长度sublen一定是str1和str2的长度的最大公因数，所以先计算两串长度len1,len2，再求出len1,len2的最大公因数，记为最大公因子串的长度sublen,把假设的substr的值赋值为str1的前sublen个元素，将substr依次和str1，str2比对，如果出现匹配不上的说明答案为空串，全匹配完的话，最后返回substr

### 代码

```c
int gcd(int a,int b)
{
   // printf("%d %d\n",a,b);
    if(0==b)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}

char * gcdOfStrings(char * str1, char * str2){
    int len1=0,len2=0;
    while(*(str1+len1)!=0)
    {
        len1++;
    }
    while(*(str2+len2)!=0)
    {
        len2++;
    }
    int sublen=gcd(len1,len2);
    char *substr;
    substr=(char*)malloc((sublen+1)*sizeof(char));
    *(substr+sublen)='\0';
    for(int i=0;i<sublen;i++)
    {
        *(substr+i)=*(str1+i);
    }

    for(int i=0;i<len1;i++)
    {
        if(*(str1+i)!=*(substr+(i%sublen)))
        {
            *substr='\0';
            return substr;
        }
    }

    for(int i=0;i<len2;i++)
    {
        if(*(str2+i)!=*(substr+(i%sublen)))
        {
            *substr='\0';
            return substr;
        }
    }
    return substr;
}
```