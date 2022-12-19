### 解题思路
同主站习题 [400. 第N个数字](https://leetcode-cn.com/problems/nth-digit/)

些微不同：
1. 当 n = 0, 输出 0
2. 主站400题，输出str("1"), 这一题需要输出 int 值 1。



### 代码

```python3
class Solution:
    def findNthDigit(self, n: int) -> int:
        if n == 0:
            return 0
        k = 1
        count = 9*1
        num = 9
        while count<n:
            k += 1
            num *= 10
            count += k*num
        old_count = count - k*num
        first = 10**(k-1)
        # (n-old_count+k-1)//k 恰好代表了需要顺延的下一个数
        # (n-old_count+k-1)%k 恰好对应了下标
        return int(str(first-1 + (n-old_count+k-1)//k)[(n-old_count+k-1)%k]) #下标从 0 开始
```