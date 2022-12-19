解题的关键有一下三点：
1. 将除数与被除数扩展至long
2. 正负号的判断，满足(t1 == dividend) ^ (t2 == divisor)则结果为负
3. 如何计算商（help()解决）
4. help结果返回的有可能是>Integer.Max_Value的所以再处理下结果即可。

```
private long help(long dividend, long divisor) {
        if (dividend < divisor) return 0;
        long t = divisor, res = 1;
        while (t+t <= dividend) {
            t += t;
            res += res;
        }
        res += help(dividend - t, divisor);
        return res;
    }

    // 100% 1ms(中文) 100% 1ms(英文)
    public int divide(int dividend, int divisor) {
        long t1 = dividend, t2 = divisor;
        t1 = t1 < 0 ? -t1 : t1;
        t2 = t2 < 0 ? -t2 : t2;
        long help = help(t1, t2);
        if ((t1 == dividend) ^ (t2 == divisor))
            return -(int)help;
        return help > Integer.MAX_VALUE ? Integer.MAX_VALUE : (int)help;
    }
```
如果对您有帮助，请给个赞^_^