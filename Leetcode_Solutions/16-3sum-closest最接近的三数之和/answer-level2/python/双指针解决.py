### 解题思路
执行结果：通过

执行用时 :40 ms, 在所有 Python 提交中击败了98.64%的用户
内存消耗 :11.7 MB, 在所有 Python 提交中击败了74.19%的用户

### 代码

```python
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        nums.sort()
        i = 0
        flag=float("inf")
        for i in range(len(nums)):
            if i == 0 or nums[i]>nums[i-1]:
                left = i+1
                right = len(nums)-1
                while left<right:
                    sum = nums[i] + nums[left] +nums[right]
                    if sum==target:
                        return target
                    elif sum<target:
                        if target-sum<flag:
                            best=sum
                            flag=target-sum
                        left+=1
                    elif sum>target:
                        if sum-target<flag:
                            best=sum
                            flag=sum-target
                        right-=1
        return best
                

```