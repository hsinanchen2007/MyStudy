1. 先排序, 在第奇数位置求和

```
class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        data = sorted(nums)
        i = 0
        SUM = 0
        # 排序
        while(i < len(data)):
          SUM += data[i]
          i += 2
        return SUM
```

更简单写法
```
class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(sorted(nums)[::2])
```
