小白在参考多种解法以后写出以下代码。
```
n = len(nums)
        nums.sort()
        for i in range(1,n):
            if nums[i-1] == nums[i]:
                return True
        return False
```
