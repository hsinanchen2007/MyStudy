### 解题思路
与之类似的还有这道题：https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
官方给出的题解思路是：找到梳轴(qvoit),梳轴左右为两段递增数据。然后根据left与目标值的大小关系，判断出是在左边用二分查找还是右边，这种思路同样适用于此题，只是在查找梳轴时，对于nums[left]==nums[mid]的情况，无法判断最大值在何处，此时单独增加一步left++.
这里参考一位博主的解法，给出一种更简单的思路,核心思路是：首先判断mid的那边是递增的，以此判断出target肯定(**注意这个定语**)存在于哪一边，调整left或right的值，否则，说明target肯定(这里与前一个肯定相对应)在相反的方向。
补充：
对于[1,2,1,1,1]或[1,1,1,2,1]这样的数组，不能一下子由mid与left的关系判断出那边是递增的，此时需要left++即可。
请看下面代码。
samll tips:
    1. mid:=left+(right-left)/2,是一种防止大数相加越界。
### 代码

```golang
func search(nums []int, target int) bool {
    if len(nums)<=0{
        return false
    }

    left:=0
    right:=len(nums)-1
    mid:=0
    for left<=right{
        mid:=left+(right-left)/2
        
        if nums[mid]==target{
            return true
        }
        //1 无法判断那边递增，left++
        if nums[mid]==nums[left]{
            left++
        }else if nums[mid]>nums[left]{ //2 说明左边递增
            if nums[mid]>target && nums[left]<=target{//2.1 通过固定两端可以肯定target，在此区间内
                right=mid-1
            }else{                                     //2.2 否则肯定在另一个区间内
                left=mid+1
            }
        }else{                          //3 说明右区间递增
            if nums[mid]<target && nums[right]>=target{
                left=mid+1
            }else{
                right=mid-1
            }
        }
    }

    return false
}
```