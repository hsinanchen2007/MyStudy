1. 去重
2. 倒序排序
3. 其他情况处理
- 无值 返回None
- len(L) >= 3 返回L[-1]
- len(L) < 3 返回的是L[0]

```
class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 去重  data = [6, 2, 1, 3, 4, 1, 10]
        # list.count(2) 方法用于统计某个元素在列表中出现的次数
        # L = filter(lambda i: nums.count(i) == 1, nums)
        O = {}
        for i in nums:
            O[i] = ''
        L = O.keys()
        # 排序 倒序排序, 去三个数
        L = sorted(L, reverse=True)
        if len(L) >= 3:
          L = L[0:3]
          # 输出最后一个
          return L[-1]
        
        # 输出最后一个
        if len(L) == 0: 
          return None
        return L[0]
```
