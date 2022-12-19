方法：某个位置i上如果最终灯亮，则i的所有因数的个数应为奇数。而只有完全平方数的因数个数为奇数，因此本质就是求n以内的完全平方数个数。
代码如下：
```
class Solution {
    public int bulbSwitch(int n) {
        if (n == 0) return 0;
        int i = 1;
        for (; i*i<=n; i++);
        return i-1;
    }
}
```
