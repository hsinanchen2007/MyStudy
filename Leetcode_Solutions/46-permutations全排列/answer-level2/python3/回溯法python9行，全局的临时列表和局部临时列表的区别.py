**全局的临时列表需要手动维护，所以回溯的时候pop或者remove是不可少的**

```
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        temp_lis = []  # 临时列表
        res = []
        len_n = len(nums)
        def back_track(nums):
            for i in range(len(nums)):
                temp_lis.append(nums[i])
                if len(temp_lis) == len_n:
                    res.append(temp_lis[:])  # 注意这里不能写为temp_lis，因为它一直在pop()，只需要append它的内容即可。
                    temp_lis.pop()
                else:
                    back_func(nums[:i]+nums[i+1:])
            if i == len_n-1:
                return
            temp_lis.pop()
        back_track(nums)
        return res
```

**局部的临时列表，back_func自己在维护**
```
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        def backtrack(nums, temp_lis):  # temp_lis为临时列表
            if not nums:
                res.append(temp_lis)
                return 
            for i in range(len(nums)):
                backtrack(nums[:i] + nums[i+1:], temp_lis + [nums[i]])
        backtrack(nums, [])
        return res
```

