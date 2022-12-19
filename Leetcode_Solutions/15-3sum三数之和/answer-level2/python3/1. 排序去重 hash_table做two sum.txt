### 解题思路
先排序，方便处理重复$Nlog(N)$
threesum 固定1个数后，转换为twosum$O(N^2)$
twosum 使用hash查找

### 代码

```python3
class Solution:
    def threeSum(self, nums):
        nums.sort()
        ans = []
        for i,num in enumerate(nums[:-2]):
            if i > 0 and num == nums[i-1]:
                continue
            two = self.twoSum(-num,nums[i+1:])
            if two != []:
                for t in two:
                    ans.append([num]+t)
        return ans

    
    def twoSum(self,target,nums):
        hash_table = {}
        ans = []
        for i,num in enumerate(nums):
            if target - num in hash_table:
                if [target-num,num] not in ans:
                    ans.append([target-num,num])
            hash_table[num] = i
        return ans

```