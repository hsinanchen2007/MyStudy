### 解题思路
还是不明白lambda的写法。。。

### 代码

```
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