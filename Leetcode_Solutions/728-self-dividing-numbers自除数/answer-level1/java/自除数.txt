####  方法一：暴力法
**算法：**
- 对于给定范围内的每个数，我们将直接判断该数是否为自除数。
- 根据定义，我们先判断数字是否非零，若数字非零再判断是否能够被该数除尽。例如，对于 `128`，我们要判断 `d != 0 && 128 % d == 0`，且 `d = 1, 2, 8`。
- 解决这个问题的一个简单方法是将数字转换成一个字符数组（python 中的字符串），然后在检查 `n%d==0` 时转换回整数执行模运算。
- 我们还可以不断地把数字除以 `10`，取整数的最后一个数字。在代码中为注释的部分。

```Python [ ]
class Solution(object):
    def selfDividingNumbers(self, left, right):
        def self_dividing(n):
            for d in str(n):
                if d == '0' or n % int(d) > 0:
                    return False
            return True
        """
        Alternate implementation of self_dividing:
        def self_dividing(n):
            x = n
            while x > 0:
                x, d = divmod(x, 10)
                if d == 0 or n % d > 0:
                    return False
            return True
        """
        ans = []
        for n in range(left, right + 1):
            if self_dividing(n):
                ans.append(n)
        return ans #Equals filter(self_dividing, range(left, right+1))
```

```Java [ ]
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> ans = new ArrayList();
        for (int n = left; n <= right; ++n) {
            if (selfDividing(n)) ans.add(n);
        }
        return ans;
    }
    public boolean selfDividing(int n) {
        for (char c: String.valueOf(n).toCharArray()) {
            if (c == '0' || (n % (c - '0') > 0))
                return false;
        }
        return true;
    }
    /*
    Alternate implementation of selfDividing:
    public boolean selfDividing(int n) {
        int x = n;
        while (x > 0) {
            int d = x % 10;
            x /= 10;
            if (d == 0 || (n % d) > 0) return false;
        }
        return true;
    */
}
```

**复杂度分析**

* 时间复杂度：$O(D)$。$D$ 是在区间 $[L, R]$ 里的整数数。
* 空间复杂度：$O(D)$，使用了一个数组来存放结果。