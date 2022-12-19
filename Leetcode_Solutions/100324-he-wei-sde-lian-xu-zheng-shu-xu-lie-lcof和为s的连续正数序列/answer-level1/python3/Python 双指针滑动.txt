## 双指针滑动
1、暴力破解，时间复杂度太高

```
  # 暴力
        res = []
        sumx = 0
        for i in range(target//2+1,1,-1):
            for j in range(i-1,0,-1):
                sumx = (i+j)*(i-j+1)/2
                # print(sumx)
                if sumx==target:
                    res.insert(0,list(range(j,i+1)))
                elif sumx<target:
                    continue
                elif sumx>target:
                    break
        return res
```


2、双指针滑动

```
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        # 双指针
        res = []
        # 左右滑动窗口
        l = 1
        r = 2
        # 最大的值
        nums = list(range(0,target//2+target%2+1)) 
        # print(nums)
        sumx = 3
        # print(nums)
        while r<len(nums):
            if sumx<target:
                r+=1
                if r == len(nums):
                    break
                sumx += nums[r]
            elif sumx==target:
                res.append(nums[l:r+1])
                sumx-=nums[l]
                # sumx-=nums[l+1]
                l+=1
                # l+=2  虽然l+=1 和 l+=2 差别不大
            elif sumx>target:
                sumx -= nums[l]
                l+=1
        return res
```
