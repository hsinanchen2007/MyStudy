和3数之和类似，先将数组排序固定两个元素在用两个指针，一个指向头，一个指向尾，看四数之和为多少，太大了右指针左移，太小了左指针右移，因为有可能存在重复的数组，先将结果保存在set中，最后在转为list输出
```python []
class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        ans=set()
        
        for i in range(len(nums)-3):
            for j in range(i+1,len(nums)-2):#固定两个数
                left=j+1#左指针
                right=len(nums)-1#右指针
                while(right>left):
                    temp=nums[i]+nums[j]+nums[left]+nums[right]
                    if temp==target:
                        ans.add((nums[i],nums[j],nums[left],nums[right]))
                        left+=1
                        right-=1
                    if temp>target:right-=1#太大了，右指针左移
                    if temp<target:left+=1#反之
        #去重
        rec=[]
        for i in ans:
            rec.append(list(i))
        return rec
        
        
```

