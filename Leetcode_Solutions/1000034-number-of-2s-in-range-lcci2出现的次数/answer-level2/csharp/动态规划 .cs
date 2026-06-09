先举个简单的例子
比如我们要求22
22可以分解成{0-9},{10-22}两部分
实际上就是1位数字，2位数字的区别。
{0-9}这部分总共有dp[9] = 1
{10-12}部分：
1开头的{10-19}因此等于dp[9]
2开头的{20-22}，等于{20,21,22}三个十位的2加上一个个位的2
十位的3个= 22-20 + 1
个位的1个=dp[2]

进而我们可以推到3位数字比如322={0-9}+{10-99}+{100-322}
dp[{0-9}] = 0 或 1
dp[{10-99}]可以根据上面的方法用一位数的dp算出来
dp[{100-322}]可以用两位数的dp算出来
以此类推
```
public class Solution {

    Dictionary<int, int> dp = new Dictionary<int, int>();
    int GetDp(int num) {
        if (num < 2) return 0;
        if (num < 10) return 1;
        var value = NumberOf2sInRange(num);
        AddDp(num, value);
        return dp[num];
    }
    void AddDp(int num, int count) {
        if (!dp.ContainsKey(num)) dp.Add(num, count);
    }

    public int NumberOf2sInRange(int n) {
        var counter = 0;
        int mod = 1;
        while (n / mod > 0) {
            var mod_10 = mod * 10;
            var cur = (n - n / mod_10 * mod_10) / mod;
            var tail = n - n / mod * mod;
            var dp_tail = GetDp(tail);
            var dp_mod = GetDp(mod - 1);
            var newCounter = dp_mod + dp_mod * (cur - 1) + dp_tail;
            if (cur > 2) {
                newCounter += mod;
            } else if (cur == 2) {
                newCounter += tail + 1;
            }
            mod *= 10;
            counter = newCounter;
            AddDp(cur * mod + tail, counter);
        }
        return counter;
    }
}
```
