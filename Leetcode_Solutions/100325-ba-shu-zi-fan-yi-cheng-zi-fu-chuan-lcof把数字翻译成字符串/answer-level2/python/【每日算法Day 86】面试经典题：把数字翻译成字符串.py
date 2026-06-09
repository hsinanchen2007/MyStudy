> 关注公众号【算法码上来】，每日算法干货马上就来！

![宣传图片.jpg](https://pic.leetcode-cn.com/b14a8ebe71d7ee569f41be01d957bcbce03878d1efe588aba0f4a77e930a723e-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)


## 题解
显然这题就是个动态规划问题，我们令 $f[i]$ 表示 $num$ 到第 $i$ 位为止表示的方法数。

那么我们观察 $num$ 的第 $i$ 位和第 $i-1$ 位，也就是最后两位，记为 $last$。如果 $10 \le last \le 25$，那么就可以把这两位合并成一个字母表示，同时也可以分成两个字母表示，所以 $f[i] = f[i-1] + f[i-2]$ 。但是如果 $last > 25$ ，那就只能分成两个字母来表示了，所以 $f[i] = f[i-1]$ 。那如果 $last < 10$ 会怎么样呢？那说明最后两位是 $0x$ 的形式，这种形式没有办法用一个字母表示，所以只能分成两个字母表示，所以 $f[i] = f[i-1]$ 。

综上，如果 $10 \le last \le 25$，就有 $f[i] = f[i-1] + f[i-2]$ ；否则的话就有 $f[i] = f[i-1]$ 。

当然上面这是把 $num$ 拆成了数字形式的字符串来做的，其实这题也可以直接用递归，这样都不用转变成字符串形式了。

我们直接令 $f(num)$ 表示数字 $num$ 的方法数。那么最后两位结果就是 $last = num \% 100$ ，那么如果 $10 \le last \le 25$，就有 $f(num) = f(num/10) + f(num/100)$ ；否则的话就有 $f(num) = f(num/10)$ 。递归的终止条件就是，如果 $num < 10$ ，那么只有一种表示方法。

当然这里递归有重复计算，可以采用记忆化搜索，但是因为复杂度太低了，没有必要。

时间复杂度为 $O(\log_{10}{num})$，也就是 $num$ 的位数。

## 代码
### c++
```cpp
class Solution {
public:
    int translateNum(int num) {
        if (num < 10) return 1;
        int res = translateNum(num/10), last = num%100;
        if (10 <= last && last <= 25) res += translateNum(num/100);
        return res;
    }
};
```

### python
```python
class Solution:
    def translateNum(self, num: int) -> int:
        if num < 10: return 1
        res, last = self.translateNum(num//10), num%100
        if 10<=last<=25: res += self.translateNum(num//100)
        return res
```