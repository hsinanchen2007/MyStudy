### 解题思路
第一次遍历：找出nums[i]>nums[i+1]的地点


这样的地点若大于或等于两个，发生至少两次递减，无法修改一个值就满足题意


若只有一个，如图
![Snip20191214_1.png](https://pic.leetcode-cn.com/d49345913a25e2c57eaf4d5a2aac0bb41c64d99f56f454e2889903a6902554ae-Snip20191214_1.png)
其中b,c是我们找出来的num[i]>nums[i+1]
b = i,c = i+1,a = i-1,d = i+2
我们比较这四个点的大小即可，对四个点的大小分类讨论，具体分析见代码

### 代码
```python3
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        counts = 0
        location = 0
        for i in range(len(nums)-1):
            if nums[i]>nums[i+1]:
                counts += 1
                location = i
            if counts>=2:
                return False
        if counts==0:
            return True
        b = location
        a = location - 1
        c = location + 1
        d = location + 2
        if b==0 or c==len(nums)-1:
            return True
        else:
            if nums[a]<=nums[c]:
                return True
            else:
                if nums[d]>=nums[b]:
                    return True
                else:
                    return False

```