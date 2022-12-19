### 解题思路
# 解法一：查找梳轴
参考官方的解题思路，做详细解答。
思路分两步：
    1.用二分法找到pivot(轴),即在pivot处最小，左边递增，右边递增
    2.确定target在pivot的哪一边，左边[0,pivot-1]单调，用二分查找，右边[pivot,len(nums)-1]单调，用二分查找
所以本题的难点思路也有两点：
    a.怎样找到pivot
    b.怎样找到target在pivot的哪一边，这个问题容易解决，只需判断nums[0]与target的关系即可。nums[0]大，target在pivot右边
      nums[0]小，target在pivot左边，可以按照最小值的定义去思考。
    下面重点解释用二分法找pivot的方式：
    (1)对于升序数组，此时一定有nums[left]<nums[right],此时pivot=0
    (2)对于非升序数组，如nums=[]
### 代码

```golang
func search(nums []int, target int) int {
    if len(nums)==0{
        return -1
    }
    pivot:=pivotIndex(nums)
    left,right:=0,0

    if nums[0]>target || pivot==0{
        left,right=pivot,len(nums)-1
    }else{
        left,right=0,pivot-1
    }

    for left<=right{
        mid:=(left+right)/2
        if nums[mid]==target{
            return mid
        }else if nums[mid]>target{
            right=mid-1
        }else{
            left=mid+1
        }
    }
    
    return -1
}

func pivotIndex(nums []int) int{
    left:=0
    right:=len(nums)-1
    if nums[left]<=nums[right]{
        return 0
    }
    for left<=right{
        mid:=(left+right)/2
        if nums[mid+1]>nums[mid]{
            if nums[left]<nums[mid]{
                left=mid+1
            }else{
                right=mid
            }
        }else{
            return mid+1
        }
    }
    return 0
}

```

# 解法二：根据递增区间，锁定target区间
这是一种梳轴问题的通用解法。
算法思路：
1. 有mid和left处的值判断mid那边是单调递增区间
2. 对于递增区间，由区间端点的值，可以判断target是否肯定(**注意这个定语**)在此区间内，然后调整left和right；否则，说明在相反的区间内。


```
func search(nums []int, target int) int {
    if len(nums)<=0{
        return -1
    }

    left:=0
    right:=len(nums)-1
    mid:=0

    for left<=right{
        mid=(left+right)/2
        if nums[mid]==target{
            return mid
        }
        //1 对于左边是递增区间
        if nums[mid]>=nums[left]{
            if nums[mid]>target && nums[left]<=target{ //1.1 [left,mid]这个区间,通过端点可以肯定target是否在此区间
                right=mid-1
            }else{                                     //1.2 不在，说明在[mid,right]区间
                left=mid+1
            }
        }else{
            if nums[mid]<target && nums[right]>=target{
                left=mid+1
            }else{
                right=mid-1
            }
        }
    }

    return -1
}
```