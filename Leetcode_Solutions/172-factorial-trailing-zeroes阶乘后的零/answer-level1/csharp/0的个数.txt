首先观察0产生的原因,
如果乘以10,一定会有0,
乘以5再乘以2也会出现0,所幸2比5小,5!里面一定会有2
问题转化成了阶乘里有多少个5或者5的倍数
很容易想到n!里面有(n / 5)个5的倍数;
直接return n / 5?
问题似乎没有那马简单 25 125这些会产生多个0的也只计算了一次,这似乎不行
还好 我们有递归 
```
 public class Solution
{
    public int TrailingZeroes(int n)
    {
        n = n / 5;
        if (n < 5)
        {
            return n;
        }
        return n  + TrailingZeroes(n);
    }

}
```

```
