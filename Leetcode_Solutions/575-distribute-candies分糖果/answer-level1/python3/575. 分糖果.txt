1. set过滤
```
class Solution(object):
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        return min(len(set(candies)), len(candies) / 2)

```
2. 哈希表
比第一种稍快，可用哈希表优化
- dict.keys()
- 排序对比
```
class Solution(object):
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        dic = {}
        for i in candies:
            if i in dic:
                dic[i] =+ 1
            else:
                dic[i] = 1
        return min(len(dic.keys()), len(candies) / 2)

```
