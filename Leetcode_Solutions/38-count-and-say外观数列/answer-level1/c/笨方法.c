### 解题思路
1）用一个大二维数组存数据；
2）知道第n-1项就可以推出第n项，让求哪一项就从第1项推到那一项；
3）存"x"个“y”中的“x”的时候要注意“x”可能是两位数或者三位数或者更大。

### 代码

```c
char * countAndSay(int n)//递归和动态内存分配用的不好，选择笨方法存数组
{
     static char aa[30][50000];
    aa[0][0]='1';
    aa[0][1]='\0';
    int i,j,k;
    for(int x=0;x<n-1;x++) //要知道第n项，就要先知道第n-1项
    {
        for(i=0,j=0,k=1;i<strlen(aa[x]);i++)
     {
        if(aa[x][i]==aa[x][i+1]) k++;
        else 
        {
            if(k<10)
            {
                char p[2];
                sprintf(p,"%d",k); //还要注意数字和字符之间的转化和赋值
                aa[x+1][j++]=p[0];
            }
            else if(k>9&&k<100)
            {
                char p[3];
                sprintf(p,"%d",k);
                aa[x+1][j++]=p[0];
                aa[x+1][j++]=p[1];
            }
            else if(k>99&&k<1000)
            {
                char p[4];
                sprintf(p,"%d",k);
                aa[x+1][j++]=p[0];
                aa[x+1][j++]=p[1];
                aa[x+1][j++]=p[2];
            }
            else printf("你输入的n值太大了！");
            aa[x+1][j++]=aa[x][i];
            k=1;
        }
     }
     aa[x+1][j]='\0';
    }
    return aa[n-1];
}
```