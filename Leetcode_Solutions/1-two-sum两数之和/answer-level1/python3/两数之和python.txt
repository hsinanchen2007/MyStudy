```
class Solution:
    def twoSum(self, nums, target):
        j=-1
        for i in range(1,len(nums)):
            temp = nums[:i]  #新建一个数组
            if (target - nums[i]) in temp: #判断另一个数是否在temp数组内
                j = temp.index(target - nums[i])   #取其索引，在temp与nums的索引相同
                break
        if j>=0:
            return [j,i]

        #简单粗暴法
        n = len(nums)
        for i in range(n):
            for j in range(i+1,n):
                if nums[i] + nums[j] == target:
                    return [i,j]
```
