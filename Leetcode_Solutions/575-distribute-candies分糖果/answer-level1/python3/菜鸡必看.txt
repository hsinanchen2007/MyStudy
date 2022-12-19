### 解题思路
使用set去重

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        sis=set(candies)
        if len(sis)>=len(candies)/2 :
            return len(candies)//2
        else :
            return len(sis)
```