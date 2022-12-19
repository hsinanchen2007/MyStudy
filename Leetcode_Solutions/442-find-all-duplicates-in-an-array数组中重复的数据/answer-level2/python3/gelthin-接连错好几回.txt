### 解题思路
参见 liweiwei 大佬的题解。桶排序。
同习题 [448. 找到所有数组中消失的数字](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/)  和 [41. 缺失的第一个正数](https://leetcode-cn.com/problems/first-missing-positive/)

还是基于桶排序，把nums[i] 放到下标 ind = nums[i]-1 的位置上去。

然后在来遍历一次数组，找出那些不在正确位置上的数，就说明其是多余的数。

刚开始一直想在放置的时候同时边记录解，发现一直出错。

后面有发现遍历过程：
+ if nums[i] != i+1 and nums[i] == nums[nums[i]-1]: 
+ if nums[i] != i+1:
只要前面放置过程没有错， 这两个语句作用是一样的。
还写错了一次：
+ while nums[i] != nums[nums[i]-1]  # 正确，只需要把 nums[i] 放到 ind = num[i]-1  的位置，这里加了一次判断，nums[i] != nums[nums[i]-1], 才 swap。
+ while nums[i] != i+1: #BUG,数组中可能不存在 i+1


### 代码

```python3
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        # n = len(nums)
        # i = 0 
        # res = []
        # while i<n:
        #     if nums[i] != i+1: # 1<=nums[i]<=n
        #         if nums[i] != nums[nums[i]-1]:
        #             tmp = nums[nums[i]-1]
        #             nums[nums[i]-1] = nums[i]
        #             nums[i] = tmp
        #             continue
        #         else:
        #             res.append(nums[i])
        #             i += 1
        #     i += 1
        # return res

        n = len(nums)
        i = 0 
        while i<n:
            while nums[nums[i]-1] != nums[i]:
                tmp = nums[i]
                nums[i] = nums[nums[i]-1]
                nums[tmp-1] = tmp
            i += 1
        res = []
        # for i in range(len(nums)):  ## 解答错误 [5,4,6,7,9,3,10,9,5,6]
        #     if nums[i] != i+1:  ## 放在了不正确的位置上，必然是错误的元素
        #         res.append(nums[i])
        for i in range(len(nums)):
            if nums[i] != i+1 and nums[i] == nums[nums[i]-1]: #确实有一个数已经放到了正确的位置
                res.append(nums[i])  # 解答错误 [13,8,5,3,20,12,3,20,5,16,9,19,12,11,13,19,11,1,10,2] 
        return res
```