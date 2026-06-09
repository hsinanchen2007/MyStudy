### 解题思路

这题其实也是数学题哦，其实就是求Z能不能整除X,Y的最大公约数。

这里分几种情况讨论：

1.当Z等于0，或者X+Y=Z时，直接返回true就好了，这算是最简单的一种情况了。

2.当X+Y<Z时，直接返回false。

3.接下来就比较复杂了，要求X，Y的最大公约数，这里的最大公约数可以理解为步进值，即X，Y两个杯子能够凑出来的水量，只能是步进值的整数倍。

具体的数学证明我忘记了，毕竟是20年前学的东西，老师只让记住了个结论，我也就只记住了个结论。。。。
![双100题解.PNG](https://pic.leetcode-cn.com/9564846ed6a3b123b51936f3c73542acf998e59a01e770cd0455b576402f2890-%E5%8F%8C100%E9%A2%98%E8%A7%A3.PNG)



### 代码

```c
bool canMeasureWater(int x, int y, int z)
{
    if(z==0||(x+y)==z)
    {
        return true;
    }
    else
    {
        if((x+y)<z)
        {
            return false;
        }
        else
        {
            for(int i=(x>y?y:x);i>=1;i--)
            {
                if((x%i)==0&&(y%i)==0)
                {
                    return z%i==0;
                }
            }
        }
    }
    return false;
}
```