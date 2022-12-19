### 解题思路
学习到两点：
1. 利用i%n来控制数组的索引
2. 利用min()来完成数据的选取

### 代码

```python
import math
class Solution(object):
    def distributeCandies(self, candies, num_people):
        """
        :type candies: int
        :type num_people: int
        :rtype: List[int]
        """
        i=0
        a=[0]*num_people
        while candies:
            a[i%num_people]+=min(i+1,candies)
            candies-=min(i+1,candies)
            i+=1
        return a
```