# 题解
本题的麻烦之处在于重复元素。最开始的想法是依旧寻找旋转数组的旋转点，但是始终通不过，所以放弃了。
由旋转排序数组的特性。排序旋转数组是由两段有序的子序列构成，分为左子列和右子列。
## 二分法
### 算法流程：

 1. 初始化左$l=0$和右指针$r=n-1$。
 2. 循环条件$l<=r$：
 	+ $mid=(l+r)//2$，若$nums[mid]==target$，返回$True$
 	+ 若$nums[mid]==nums[l]==nums[r]$，将左右指针同时向里移一位，$l+=1,r-=1$。
 	+ 若$nums[mid]>=nums[l]$，说明此时$mid$在左子列中：
 		* 若此时$nums[l]<=target<nums[mid]$，说明$target$在左子列中，则此时令$r=mid-1$。否则，令$l=mid+1$
 	+ 否则，说明$mid$在右子列中：
 		* 若$nums[mid]<target<=nums[r]$，说明$target$在右子列中，则此时令$l=mid+1$。否则令$r=mid-1$。
 
 3. 返回False

### 复杂度分析
 - 时间复杂度：$O(\log n)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def search(self, nums: List[int], target: int) -> bool:        
        l=0
        r=len(nums)-1
        while(l<=r):
            mid=(l+r)//2
            if(nums[mid]==target):
                return True
            if(nums[mid]==nums[l]==nums[r]):
                l+=1
                r-=1
            elif(nums[mid]>=nums[l]):
                if(nums[l]<=target<nums[mid]):
                    r=mid-1
                else:
                    l=mid+1
            else:
                if(nums[mid]<target<=nums[r]):
                    l=mid+1
                else:
                    r=mid-1
        return False
```