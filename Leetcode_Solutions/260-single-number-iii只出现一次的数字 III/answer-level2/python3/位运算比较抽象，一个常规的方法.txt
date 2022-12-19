思路很简单。因为数字只出现一次或两次
数字第一次出现，放进容器里。
数字再次出现，从容器里删除。
剩下来的就是两个只出现一次的数字咯。

```
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        ans = set()　　　#初始化一个集合
        for i in nums:
            if i in ans:　　#数字已经存在，删除
                ans.remove(i)
            else:           #数字不存在，添加
                ans.add(i)
        return ans

```
