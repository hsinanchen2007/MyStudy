### 解题思路
因为今天参加某个公司的笔试题，一个小时两道题，一个都没有做出来。所以来这里联系算法，从最基础的开始。思路应该是最笨的。

### 代码

```python3
class Solution:
    def twoSum(self, nums,target):
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[i] +nums[j] == target:
                    return [i,j]
                else:
                    continue

solution = Solution()
a = solution.twoSum([2,7,11,15,2,6,98,23], 13)
print(a)

```