#  方法一：Python内置函数，取表尾（并将其删除）加入到表头，循环k次
```
class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        k=k%len(nums)
        for i in range(k):
            nums.insert(0,nums.pop())
        
        return nums
```

# 方法二：反转法
- 将列表反转
- 将前k个元素反转
- 将后n-k个元素反转
```
class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n=len(nums)
        if n<=0:
            return False
        elif n==1:
            return nums
        else:
            k=k%n
            self.reverse(nums,0,n-1)
            self.reverse(nums,0,k-1)
            self.reverse(nums,k,n-1)
        return nums
    def reverse(self,nums,start,end):
        while start<end:
            nums[start],nums[end]=nums[end],nums[start]
            start+=1
            end-=1
```

#  方法三：
```
class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        k=k%len(nums)
        t=nums[-k:]
        nums[k:]=nums[:-k]
        nums[:k]=t
```