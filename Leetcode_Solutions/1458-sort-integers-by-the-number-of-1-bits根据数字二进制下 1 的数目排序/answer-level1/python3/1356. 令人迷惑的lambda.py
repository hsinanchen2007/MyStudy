### 解题思路
还是不明白lambda的写法。。
lambda: sorted()函数里这个参数key接收一个匿名函数。先按照二进制中1的个数排序(bin(x).count('1'))，再按照数值大小排序(x)。
### 代码

```python3
class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        def count(num):
            counts = 0
            while num:
                num &= num-1
                counts += 1
            return counts
        
        return sorted(arr, key=lambda x:(count(x),x))
```