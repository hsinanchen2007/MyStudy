### 解题思路
用双指针方法 slow在最前面 fast在1处 每次fast数字与slow比较 若相等 fast继续往前走
若不相等 fast的位置放在slow中 说明之前slow中的数字遍历完了 slow++ fast++。

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if (len(nums)==0): return 0
        if (len(nums)==1): return 1
        slow = 0
        for fast in range(1,len(nums)):
            if(nums[fast]!=nums[slow]):
                slow += 1
                nums[slow] = nums[fast]
        return slow+1

            
```