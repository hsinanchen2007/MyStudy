# 分析法和动态规划
1. 方法一：直接分析法
```
class Solution
{
public:
    bool divisorGame(int N)
    {
        int count = 0;
        int num = N;
        while (num != 1)
        {
            int x = 1;
            while (num % x != 0)
            {
                x++;
            }
            num = num - x;
            count++;
        }
        if (count % 2 == 0)
        {
            return 0;
        }
        return 1;
    }
};
```
1. 方法二：动态规划
```
class Solution
{
public:
    bool divisorGame(int N)
    {
        int f [N+1];
        for (int i=0;i<=N;i++)
        {
            f[i]= 0;
        }
        f[1]=0;
        if(N<=1)
            return 0;
        f[2]=1;


        for (int i = 3; i <= N; i++)
        {
            for(int j=1;j<=(i/2);j++)
            {
                if (i%j==0 and f[i-j]==0)
                {
                    f[i] =1;
                }
            }
        }
        return f[N]==1;
        
    }
};
```



