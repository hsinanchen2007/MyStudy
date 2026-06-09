### 解题思路
先给数组排序，假设[1,2,4,5,6], target=5
我们知道如果1+5>5,就没必要重复run一遍1+6

### 代码

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        sort_nums=sorted(nums) #if x<y<z, and x+y>t,then y+z>t
        #all combiniation=n*(n-1)/2
        leng=len(nums)
        for i in range(leng):
            first=sort_nums[i]
            for j in range(i+1,leng):
                candid=sort_nums[j]
                if first+candid==target:
                    if first!=candid:
                        return [nums.index(first),nums.index(candid)]
                    else: 
                        first_id=nums.index(first)
                        return[nums.index(first),nums[first_id+1:].index(first)+first_id+1]
                elif first+candid<target:
                    continue
                else:
                    break
```