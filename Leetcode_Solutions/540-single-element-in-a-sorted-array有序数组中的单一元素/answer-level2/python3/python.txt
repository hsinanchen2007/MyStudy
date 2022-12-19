### 解题思路
先将nums存入字典，然后利用字典进行求解。（执行用时还是很菜）

### 代码

```python3
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        nums.sort()
        dic = {}
        for i,j in enumerate(nums):
            dic[j] = i
        print(dic)
        now = -1
        for i in dic:
            if dic[i]-now == 2:
                now = dic[i]
            else:
                return i
       
```