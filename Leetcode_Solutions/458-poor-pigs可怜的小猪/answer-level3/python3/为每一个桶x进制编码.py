### 解题思路
此处撰写解题思路

### 代码

```python
class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        states = minutesToTest//minutesToDie +1
        if states ==1:
            return 
        return math.ceil(math.log(buckets)/math.log(states))#int +1 no int +0 float +1
```