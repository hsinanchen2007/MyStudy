### 注意事项
1. 判断是否重复时的 `if k>0 and...`不可省略，不然会漏掉000的情况
2. `continue`仅跳过本次循环
3. list.append 只能接受一个变量，所以返回时以数组传递

### 代码

```python3

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        nums.sort()
        res,k = [] ,0
        for k in range(len(nums)-2):
            if nums[k] > 0:break
            if k>0 and nums[k] == nums[k-1]:continue
            i,j = k+1,len(nums)-1
            while i<j:
                s = nums[i]+nums[j]+nums[k]
                if s > 0:
                    j -= 1
                    while i<j and nums[j]==nums[j+1]:j -= 1
                elif s < 0:
                    i += 1
                    while i<j and nums[i]==nums[i-1]:i +=1
                else:
                    res.append([nums[k],nums[i],nums[j]])
                    j -= 1
                    i += 1
                    while i<j and nums[i]==nums[i-1]:i +=1               
                    while i<j and nums[j]==nums[j+1]:j -= 1
        return res
```