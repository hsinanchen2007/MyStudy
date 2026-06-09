### 解题思路
此处撰写解题思路                                                          
![QQ截图20200402133356.png](https://pic.leetcode-cn.com/9b50ff00038572de6bf2f95f7e81c2d2c7cbf9fb9c98332588cc2f5e065b8094-QQ%E6%88%AA%E5%9B%BE20200402133356.png)
### 代码
char* compressString(char* S)
{  int len=strlen(S);
   if(len<2)
    return S;
   char *res=(char *)malloc(sizeof(char)*(2*len+1));
   int i,j,k=0;
   char m;
   for(i=0;i<len;)
   { j=1;
     res[k]=S[i];
     k++;
     m=S[i];
     i++;
     while(S[i]==m)
     { j++;
       i++;
     }
     int p,q;
     p=(int)log10(j);
     q=p;
     for(p;p>=0;p--)
     { res[k+p]=j%10+'0';
       j=j/10;
     }
     k=k+q+1;
   }
   res[k]='\0';
   if(k>=len)
     return S;
   else
     return res;
}