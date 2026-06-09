### 解题思路
使用两次二分法。
令res=[-1,-1]
1. 第一次二分法查找位于最左侧的目标值：
令left1=0；right1=len(nums)-1；mid1=(left1+right1)//2
当left1<=right1时：
    1.1.若nums[mid1]<target，说明目标值在mid1右侧，此时left1 = mid1+1
    1.2.若nums[mid1]>target，说明目标值在mid1左侧，此时right1 = mid1-1
    1.3.若nums[mid1]=target:
        1.3.1.若mid1=0，则说明mid1已经位于最左侧，此时最左侧的target位置即为mid1
        1.3.2.若nums[mid1-1]>=target，左侧仍有=target的值，说明还需要左移，所以right1=mid1-1
        1.3.3.若nums[mid1-1]<target，左侧已没有=target的值，此时最左侧的target位置即为mid1

2. 第二次二分法查找位于最右侧的目标值：
令left2=0；right2=len(nums)-1；mid2=(left2+right2)//2
当left2<=right2时：
    1.1.若nums[mid2]<target，说明目标值在mid2右侧，此时left2 = mid2+1
    1.2.若nums[mid2]>target，说明目标值在mid2左侧，此时right2 = mid2-1
    1.3.若nums[mid2]=target:
        1.3.1.若mid2=len(nums)-1，则说明mid2已经位于最右侧，此时最右侧的target位置即为mid2
        1.3.2.若nums[mid2-1]<=target，右侧仍有=target的值，说明还需要右移，所以left2=mid2+1
        1.3.3.若nums[mid1-1]>target，右侧已没有=target的值，此时最右侧的target位置即为mid2
返回res

算法时间复杂度：*2log(N)**~log(N)*

### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        res=[-1, -1]
        left1 = left2 = 0
        right1 = right2 =len(nums)-1
        mid1 = mid2 =(left1+right1)//2
        while left1<=right1:  #判断左侧值
            if nums[mid1]<target:
                left1 = mid1+1
            elif nums[mid1]>target:
                right1 = mid1-1
            else:
                if mid1==0:   #已经移动到最左侧，无法左移
                    res[0]=mid1
                    break
                elif nums[mid1-1]>=target:     #nums[mid-1]>=target，左侧仍有=target的值，说明还需要左移
                    right1 = mid1-1
                else:
                    res[0]=mid1   #nums[mid-1]>=target，左侧没有有=target的值，当前值即为左侧值
                    break
            mid1=(left1+right1)//2
        
        while left2<=right2:
            if nums[mid2]<target:
                left2=mid2+1
            elif nums[mid2]>target:
                right2=mid2-1
            else:
                if mid2==len(nums)-1:  #已经移动到最右侧，无法右移
                    res[1]=mid2
                    break
                elif nums[mid2+1]<=target: #nums[mid2+1]<=target，右侧仍有=target的值，说明还需要右移
                    left2=mid2+1
                else:
                    res[1]=mid2
                    break
                
            mid2=(left2+right2)//2
            
        return res
```