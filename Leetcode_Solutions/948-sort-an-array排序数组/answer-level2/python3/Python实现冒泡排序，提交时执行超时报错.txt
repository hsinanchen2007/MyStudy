```python
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        # print( len(nums))
        if len(nums)<=1:
            return nums
        for i in range(len(nums)):
            for j in list(range(len(nums)))[i+1:]:
                # print(i,j)
                # print(nums[i],nums[j])
                if nums[i]>nums[j]:
                    nums[i],nums[j]=nums[j],nums[i]
        return nums
```
本身执行的时候成功了，但是提交的时候报错了。
原因可能是，报错时输入list内容比较多，使用Python的range会重新生成一个list使得使用的空间和时间都很大
所以最后提交检验的时候`超出时间限制`

---

优化修改 2019-10-31 10:45:26

使用while循环代替for循环，可以不用range生成list，避免空间和时间消耗。提交的时候依然提示`超出时间限制`
```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        # print( len(nums))
        if len(nums)<=1:
            return nums
        i = 0
        nums_len=len(nums)
        while i < nums_len - 1:
            j = i + 1
            while j < nums_len:
                if nums[i] > nums[j]:
                    nums[i], nums[j] = nums[j], nums[i]
                j = j + 1
            i = i + 1
        return nums
```

但是还有其他可以解决的方案吗？求大佬指点