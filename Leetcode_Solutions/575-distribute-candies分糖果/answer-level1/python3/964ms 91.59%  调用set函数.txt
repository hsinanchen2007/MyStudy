### 解题思路
调用set函数可以直接找出非重复元素

同时还有一种方法是通过建立list，自己进行统计，但是这种方法耗时很长

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        return min(len(set(candies)),len(candies)//2)

```

建立list进行统计
```
class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        s = {}
        l = len(candies)
        for c in candies:
            if c in s:
                s[c] += 1
            else:
                s[c] = 1
        k = len(s)
        for c in s.values():
            sum += c - 1
        if sum >= l / 2:
            return k
        else:
            return k - l / 2 + sum


```
