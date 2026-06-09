### 解题思路
第一次二分，确定target的大致范围
第二次二分，分别寻找左边范围和右边范围
执行用时 :36 ms, 在所有 Python3 提交中击败了93.04%的用户
内存消耗 :14.7 MB, 在所有 Python3 提交中击败了5.35%的用户
### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l, r = 0 , len(nums)-1
        if r<0: return[-1,-1]
        while l<r :
            m = l+(r-l)//2
            if nums[m]<target:
                l = m+1
            elif nums[m]>target:
                r = m
            else:
                break
        if l==r:
            if nums[l]!=target:return [-1,-1]
            return [l,l]
        middle = m
        if nums[l]==target:
            res=[l]
        else:
            
            while l<m:
                m1 = l+(m-l)//2
                if nums[m1]<target and nums[m1+1]==target:
                    res=[m1+1]
                    break
                elif nums[m1]==target:
                    m = m1
                else:
                    l = m1+1
        if nums[r]==target:
            return res+[r]
        else:            
            m = middle
            while m<r:
                m2 = m+(r-m)//2
                if nums[m2]==target and nums[m2+1]>target:
                    return res+[m2]
                elif nums[m2]>target:
                    r = m2
                else:
                    m = m2+1


```