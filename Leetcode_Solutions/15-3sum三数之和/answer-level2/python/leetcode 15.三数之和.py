思路：
1.当列表元素少于3个，直接返回空列表
2.对列表排序
3.固定一个标签i，用于遍历列表
4.用两个指针，左指针j，右指针k，当结果偏小时，指针向右移，当结果偏大，右指针向左移动，与目标相等则加到结果。
5.去重：当标签i的元素等于上一个元素时，直接跳出循环。
当指针的当前元素与下一个元素相等时，直接跳过。

代码：
```
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result=[]
        if len(nums)<3:
            return result
        else:
            nums.sort()
            for i in range(len(nums)-1):
                if i>0:
                    if nums[i]==nums[i-1]:
                        continue
                j=i+1
                k=len(nums)-1
                while j<k:
                    sum=nums[i]+nums[j]+nums[k]
                    if sum==0:
                        tmp=[nums[i],nums[j],nums[k]]
                        result.append(tmp)
                        while j<k and nums[j]==nums[j+1]:
                            j+=1
                        while j<k and nums[k]==nums[k-1]:
                            k-=1
                        j+=1
                        k-=1
                    elif sum<0:
                        j+=1
                    else:
                        k-=1
            return result
```