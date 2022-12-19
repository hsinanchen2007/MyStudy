以 x = 3, target = 365 为例

正确的拆分是：
243 + 81 + 27 + 9 + 3 + 2

也就是
3 * 3 * 3 * 3 * 3 + 3 * 3 * 3 * 3 + 3 * 3 * 3 + 3 * 3 + 3 + 3 - 3 / 3

递归拆分，问题就可以逐步分治，变成二叉搜索，最后递归到简单的情形。

```python
class Solution:
    def leastOpsExpressTarget(self, x: int, target: int) -> int:
        if target == x: # 不需要操作符的情况
            return 0
        elif target == 1: # 如果 x 不是 1，想凑出 1 就只能 x / x 一个操作符
            return 1
        elif x == 1: # 如果 x 是 1，想凑出 target 只能是 1 + 1 + ... + 1
            return target - 1
        elif target < x: # x/x + x/x + ... x/x 或者 x - x/x - x/x - ... - x/x
            return min(2 * target - 1, 2 * (x - target))
        else: # 分解成 t = x^{n} + d 或者 t = x^{n+1} - d，其中 d < t
            exponent = 1
            power = x
            while power < target:
                power *= x
                exponent += 1
            if power == target:
                return exponent - 1
            lower_nearest = power // x
            lower_exponent = exponent - 1
            lower_diff = target - lower_nearest
            higher_nearest = power
            higher_exponent = exponent
            higher_diff = higher_nearest - target
            if lower_diff < target:
                lower_result = lower_exponent - 1 + 1 + self.leastOpsExpressTarget(x, lower_diff)
            else:
                lower_result = 1145141919 # 剪掉 d >= t 的情况
            if higher_diff < target:
                higher_result = higher_exponent - 1 + 1 + self.leastOpsExpressTarget(x, higher_diff)
            else:
                higher_result = 1145141919 # 剪掉 d >= t 的情况
            return min(lower_result, higher_result)
```

情况讨论清楚了，代码就很容易写出。
中间结果没有 cache，如果用哈希表，性能会更好。