### 解题思路
疑问：删去关于处理列表长度为二的代码，，运行时间更长，这是为什么呢？
### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n =len(nums)
        left =0 
        right =n-1
        k=[]
        while target not in nums:
            return [-1,-1]
        if len(nums) == 2:
            if nums[0] == target:
                k.append(0)
            if nums[1] == target:
                k.append(1)
            if len(k) == 1:
                return k*2
            else:
                return k 
        while left <=right:
            mid =(left+right)//2
            if nums[mid] == target :
                if  mid==0 or nums[mid-1]!=target:
                    k.append(mid)
               
                    break   
                else:
                    right=mid
                 
            elif nums[mid]<target:
                left = mid+1
            else:
                right = mid-1
        left =0 
        right =n-1
        while left <=right:
            mid =right-(right-left)//2
            if nums[mid] == target:
                if  mid==n-1 or nums[mid+1]!=target :
                    k.append(mid)
                    break   
                else:
                    left=mid
            elif nums[mid]<target:
                left = mid+1
            else:
                right = mid-1
        return k
        
```