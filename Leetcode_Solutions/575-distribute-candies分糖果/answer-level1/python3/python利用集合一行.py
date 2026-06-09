### 解题思路
不解释。。。。

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        return len(set(candies)) if len(set(candies))<=len(candies)//2 else len(candies)//2
```