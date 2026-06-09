### 解题思路
思路比较简单暴力：
- 首先将[0, N-1]的数字声明为一个数组；
- 根据剔除规则，每次将指定位置的数字删除之后，记录下该位置的索引，同时将数组的元素数目减去1；
- 然后，最重要的操作就是，根据要求，寻找新的要剔除的位置，这属于索引操作，找个例子推导下，应该比较容易找到；
- 之后就是循环操作，直到数组中元素数量为1的时候停止；
- 输出这最后一个数字即是所求答案；

### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        idx = 0
        digits = list(range(n))
        while digits and n > 1:
            t = (idx + m-1) % n
            digits.pop(t)
            idx = t + 0
            n -= 1
            
        return digits[0]
        pass
```