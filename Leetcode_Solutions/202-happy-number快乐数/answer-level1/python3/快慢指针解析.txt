快乐数（happy number）有以下的特性：在给定的进位制下，该数字所有数位(digits)的平方和，得到的新数再次求所有数位的平方和，如此重复进行，最终结果必为1。以十进位为例：
2 8 → 2²+8²=68 → 6²+8²=100 → 1²+0²+0²=1
3 2 → 3²+2²=13 → 1²+3²=10 → 1²+0²=1
3 7 → 3²+7²=58 → 5²+8²=89 → 8²+9²=145 → 1²+4²+5²=42 → 4²+2²=20 → 2²+0²=4 → 4²=16 → 1²+6²=37……
因此28和32是快乐数，而在37的计算过程中，37重覆出现，继续计算的结果只会是上述数字的循环，不会出现1，因此37不是快乐数。
不是快乐数的数称为不快乐数（unhappy number），所有不快乐数的数位平方和计算，最後都会进入 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4 的循环中。

**综上所述，快乐数有各自位上的数字平方和相加的结果再次重复上一次操作最终得到1这个单线过程。
而非快乐数的循环过程无法是得到1，而且是个循环的过程，也就是说有环。
而这也正是快慢指针使用的场景。**

reference：https://baike.baidu.com/item/%E5%BF%AB%E4%B9%90%E6%95%B0/655501

```python []
class Solution:
    def sum(self, n: int) -> int:
        result = 0
        while n >= 1:
            a = n % 10
            result += a ** 2
            n //= 10
        return result

    def isHappy(self, n: int) -> bool:
        slow, fast = n, self.sum(n)
        while fast != slow:
            slow = self.sum(slow)
            fast = self.sum(fast)
            fast = self.sum(fast)
        return slow == 1
```
```swift []
class Solution {
    func sum(n: Int) -> Int {
        var number = n
        var result = 0
        while number >= 1 {
            let a = number % 10
            result += a * a
            number /= 10
        }
        return result
    }

    func isHappy(_ n: Int) -> Bool {
        var (low, fast) = (n, sum(n: n))
        while low != fast {
            low = sum(n: low)
            fast = sum(n: fast)
            fast = sum(n: fast)
        }
        return low == 1
    }
}
```

