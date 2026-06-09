# 题解
本题看到时间复杂度需要在$O(\log n)$级别，所以想到二分查找
本题两个特殊之处

 1. 有序，可使用二分查找
 2. 旋转数组，需要找到旋转点，才能进行二分查找

## 二分法
### 算法流程：

 1. 特判：数组长度为0，返回-1. 数组长度为1，若$nums[0]==target$,返回0，否则返回-1。（这个特例无法按照算法流程计算，所以需要单独判断）
 2. 二分法寻找旋转点：
 	* 如果首元素小于尾元素，说明未旋转，返回0
 	* 定义左指针$l$和右指针$r$，当$l<=r$时，进入循环，接下来有两种写法，但是始终返回**旋转点为最小值的索引**：
 	+ $rotate=(l+r)//2$，如果$nums[rotate]<nums[rotate-1]$,此时返回$rotate$，判断是否满足$nums[rotate]>nums[r]$，**注意！一定是和右端比大小**若满足说明旋转点在右端，令$l=rotate+1$,否则在左端，令$r=rotate-1$。
 	+ $rotate=(l+r)//2$，如果$nums[rotate]>nums[rotate+1]$,此时返回$rotate+1$，判断是否满足$nums[rotate]<nums[l]$，**注意！一定是和左端比大小**若满足说明旋转点在左端，令$r=rotate-1$,否则在右端，令$l=rotate+1$。
 3. 若旋转点索引$rotateindex=0$，说明未旋转，则直接二分查找$find(0,n-1)$，返回索引
 4. 判断$target>=nums[0]$，如果满足，说明在旋转段的较大段，$find(0,rotateindex)$，否则$find(rotateindex,n-1)$



### 复杂度分析
 - 时间复杂度：$O(\log n)$+$O(\log n)$,$O(\log n)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def find_rotateindex(l,r):
            if(nums[l]<nums[r]):
                return 0
            while(l<=r):
                rotate=(l+r)//2
                if(nums[rotate]<nums[rotate-1]):
                    return rotate
                
                if(nums[rotate]>nums[r]):
                    l=rotate+1
                else:
                    r=rotate-1
        #print(find_rotateindex(0,len(nums)-1))
        def find(l,r):
            while(l<=r):
                mid=(l+r)//2
                if(nums[mid]==target):
                    return mid
                if(nums[mid]>target):
                    r=mid-1
                else:
                    l=mid+1
            return -1
        n=len(nums)
        if(n==0):
            return -1
        if(n==1):
            return 0 if(nums[0]==target) else -1
        rotateindex=find_rotateindex(0,n-1)
        if(rotateindex==0):
            return find(0,n-1)
            
        if(target>=nums[0]):
            return find(0,rotateindex)
        else:
            return find(rotateindex,n-1)
```