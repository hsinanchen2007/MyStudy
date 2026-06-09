### 解题思路
![QQ截图20200308212538.png](https://pic.leetcode-cn.com/dd04518e080b086e35397c6474e9ffed84b4a21f3f00adce7e756b137e7c9e31-QQ%E6%88%AA%E5%9B%BE20200308212538.png)

用了sort()，相当于作弊了
### 代码

```python3
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        nums_sort=sorted(nums)
        res=[]
        for each_num in nums:
            temp=nums_sort.index(each_num)
            res.append(temp)
        return res
```