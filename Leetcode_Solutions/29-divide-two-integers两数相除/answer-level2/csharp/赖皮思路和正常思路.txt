### 解题思路
先说赖皮思路，有这个思路是因为题目描述不严谨（也可能是故意留下的方法），如果除了加减法和位移以外，还能考虑指数对数，那么a/b可以用floor(e^(lna-lnb))这样的公式替代。
当然，由于对数的入参必须为正数，所以要把负数变正数，就得考虑-2^31的问题，所以之前的修正会比较多。代码如下：
### 代码

```csharp
public class Solution {
    public int Divide(int dividend, int divisor) {
        // 溢出判断
        if (divisor == 0)
        {
            return int.MaxValue;
        }

        if (dividend == 0)
        {
            return 0;
        }

        int resJudge = 0;
        bool resPositive = true;    // 默认正数

        if (dividend == int.MinValue)
        {
            // 可能溢出
            if (divisor == -1)
            {
                // 溢出
                return int.MaxValue;
            }
            else if (divisor == 1)
            {
                // 中间值可能溢出
                return int.MinValue;
            }
            else if (divisor == int.MinValue)
            {
                return 1;
            }

            // 防止中间值移除的处理
            if (divisor > 0)
            {
                resJudge = -1;
                dividend += divisor;
            }
            else
            {
                resJudge = 1;
                dividend -= divisor;
            }
        }

        if (dividend < 0)
        {
            if (divisor < 0)
            {
                if (dividend > divisor)
                {
                    return resJudge;
                }
                else if (dividend == divisor)
                {
                    return 1 + resJudge;
                }
                divisor = -divisor;
            }
            else
            {
                if (dividend > -divisor)
                {
                    return resJudge;
                }
                else if (dividend == -divisor)
                {
                    return -1 + resJudge;
                }

                resPositive = false;
            }
            dividend = -dividend;
        }
        else
        {
            if (divisor < 0)
            {
                if (-dividend > divisor)
                {
                    return resJudge;
                }
                else if (-dividend == divisor)
                {
                    return -1 + resJudge;
                }

                divisor = -divisor;
                resPositive = false;
            }
            else
            {
                if (dividend < divisor)
                {
                    return resJudge;
                }
                else if (dividend == divisor)
                {
                    return 1 + resJudge;
                }
            }
        }

        if (resPositive)
        {
            return (int)Math.Floor(Math.Exp(Math.Log(dividend) - Math.Log(divisor))) + resJudge;
        }
        else
        {
            return -(int)Math.Floor(Math.Exp(Math.Log(dividend) - Math.Log(divisor))) + resJudge;
        }
    }
}

```

下面是常规思路的代码

### 代码

```csharp
public class Solution {
    public int Divide(int dividend, int divisor) {
        // 短路判断
        if (divisor == 0)
        {
            return int.MaxValue;
        }
        else if (divisor == 1)
        {
            return dividend;
        }
        else if (divisor == -1)
        {
            return dividend == int.MinValue ? int.MaxValue : -dividend;
        }

        if (dividend == 0)
        {
            return 0;
        }
        if (dividend == divisor)
        {
            return 1;
        }

        bool resPositive = true;    // 默认正数

        if (dividend == int.MinValue)
        {
            // 可能溢出
            if (divisor == -1)
            {
                // 溢出
                return int.MaxValue;
            }
            else if (divisor == 1)
            {
                // 中间值可能溢出
                return int.MinValue;
            }
            else if (divisor == int.MinValue)
            {
                return 1;
            }
        }

        // 判断最终符号位
        resPositive = ((dividend ^ divisor) | int.MaxValue) == int.MaxValue;

        // 将两个数字都转为负数
        if (dividend>0)
        {
            dividend = -dividend;
        }

        if (divisor >0)
        {
            divisor = -divisor;
        }

        if (dividend>divisor)
        {
            return 0;
        }

        int res = 0, resTmp = 1;

        int edge = int.MinValue >> 1;
        // 先快速逼近到最大
        while (dividend < divisor && divisor >= edge)
        {
            divisor <<= 1;
            resTmp <<= 1;
        }

        if (dividend == divisor)
        {
            // 相等直接出答案
            if (resPositive)
            {
                return resTmp;
            }
            else
            {
                return -resTmp;
            }
        }
        else if (dividend > divisor)
        {
            // 除数左移过头了，右移一位
            divisor >>= 1;
            resTmp >>= 1;
            res = resTmp;
            dividend -= divisor;
        }
        else //if (dividend < divisor)
        {
            // 除数到临界了，就只是把resTmp记录到res中
            res = resTmp;
            dividend -= divisor;
        }

        // 开始向0逼近
        while(resTmp>0)
        {
            if (dividend > divisor)
            {
                divisor >>= 1;
                resTmp >>= 1;
            }
            else if (dividend == divisor)
            {
                // 相等，直接计算返回值
                res += resTmp;
                if (resPositive)
                {
                    return res;
                }
                else
                {
                    return -res;
                }
            }
            else
            {
                dividend -= divisor;
                res += resTmp;
                divisor >>= 1;
                resTmp >>= 1;
            }
        }

        if (resPositive)
        {
            return res;
        }
        else
        {
            return -res;
        }
    }
}
```