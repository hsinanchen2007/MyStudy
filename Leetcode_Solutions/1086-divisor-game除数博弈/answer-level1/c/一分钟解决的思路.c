### 解题思路
没有那些神仙思路，按照最简单的模拟来做。
如果到了决定输赢的局面，那此时N一定为质数，到了N为质数的情况下，此时到了谁的回合，谁就输。
所以最好想的思路就是判断质数。一分钟搞定！！

### 代码

```c


bool divisorGame(int N)
{
    if(N==1)
        return false;
    int ords=0;
    int i;
    while(1)
    {
        for(i=1;i<N;i++)
        {
            if(N%i==0)
            {
                N=N-i;    
                break;
            }
        }
        if(i==N)
        {
            if(ords==0)
                return true;
            else
                return false;
        }
        ords=(ords+1)%2;
    }
}


```