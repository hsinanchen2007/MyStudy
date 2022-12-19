```
bool canThreePartsEqualSum(int* A, int ASize)
{
    int sum=0;
    int part=0;
    int x=0;
    int count=0;
    for(int i=1;i<=ASize;i++)
    {
        sum+=A[i-1];
    }
   
    if(sum%3!=0)
    {
        return 0;
    }
    else
    {
        part=sum/3;
      
        for(int i=1;i<=ASize;i++)
        {
            x+=A[i-1];
            if(x!=part)
            {
                continue;
            }else
            {
                x=0;
                count++;
            }
        }
    }
    if(count==3 && x==0)
    {
        return 1;
    }
    else if(count>=3 && x==0 && part==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
```
求和，算出分布是否可以被三整除，可以则继续计算，否则返回0；
逐个累加，若出现X=part，x归零，计数器+1；
遍历之后分析结果：
x=0,且计数器=3，返回1；
否则返回0

特殊情况：sum=0 part=0
若计数器>=3,说明有n个0可以合并 返回值为1