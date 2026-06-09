### 解题思路
此处撰写解题思路
![QQ截图20200404113332.png](https://pic.leetcode-cn.com/df3b89aee19a456b4c1c0def312af9e9bacddd9a37e20ea6680473e5410ede6d-QQ%E6%88%AA%E5%9B%BE20200404113332.png)

### 代码

```c
char * gcdOfStrings(char * str1, char * str2)
{  int len1,len2;
   len1=strlen(str1);
   len2=strlen(str2);
   int i,j,k,m,n,p,q,a,b;
   n=len1>len2?len2:len1;
   m=len1>len2?len1:len2;
   while(n!=0)
   { p=m%n;
     m=n;
     n=p;
   }
   for(i=m;i>=1;i--)
   { if(len1%i==0&&len2%i==0)
     { j=len1/i;
       k=len2/i;
       p=0;
       while(str1[p]==str2[p]&&p<i)
           p++;
       if(p==i)
       {  for(n=0;n<i;n++)
           { for(q=0;q<j-1;q++)
             { if(str1[n+q*i]!=str1[n+(q+1)*i])
                 break;
             }
           }
           for(a=0;a<i;a++)
           { for(b=0;b<k-1;b++)
             { if(str2[a+b*i]!=str2[a+(b+1)*i])
                 break;
             }
           }
           if(n==i&&q==j-1&&a==i&&b==k-1)
           { char *res=(char *)malloc(sizeof(char)*(i+1));
             for(a=0;a<i;a++)
               res[a]=str1[a];
             res[a]='\0';
             return res;
           }
       }
     }
   }
   return "";
}
```