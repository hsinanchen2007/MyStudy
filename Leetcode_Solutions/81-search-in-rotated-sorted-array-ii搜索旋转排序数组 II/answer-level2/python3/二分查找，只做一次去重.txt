### 解题思路
我的做法是在33题的基础上：

1. 可能切分点左右的数字是同一个，此时把左边的多余的数字去掉
2. 循环时如果 nums[mid] == nums[right] 则令 right=mid

感觉讲不太清楚为什么能行，有没有朋友可以帮忙证明一下

### 代码

```python3
# 与33题不同点在于，可能切分点左右的数字是同一个

class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        if not nums:
            return False
        if nums[-1]==target:
            return True

        l,h = 0,len(nums)-1
        while nums[l]==nums[-1]:
            l += 1
            if l == len(nums):
                return False
            
        if nums[l]==target:
            return True
            
        minmax = nums[-1]
        bigger = target>minmax

        lp = -1
        while True:
            # print(l,h)
            
            p = (l+h)//2
            if lp == p:
                return False
            lp = p 
            
#             print(p,lp)
            
            t = nums[p]

            if t == target:
                return True
            elif t == nums[h]:
                h = p
            elif target > t:
                if bigger:
                    if t < minmax:
                        h = p
                    else:
                        l = p
                else:
                    l = p
            else:
                # target < t
                if bigger:
                    h = p
                else:
                    if t < minmax:
                        h = p
                    else:
                        l = p
            
            
```