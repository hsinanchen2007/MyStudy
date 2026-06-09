### 解题思路
此处撰写解题思路
一种很简单的思路就是调用两次二分查找，第一次查找右边界，第二次查找左边界，这样算法复杂度是2log(n),及logn^2不符合要求
但是我们可以稍作修改，就可以减少一次查找过程
修改的部分如下：
    还是使用一次二分查找，但是，在意思搜索时，既查找左边界，右查找右边界，使用left，right和mid1记录左边界
    使用low，right和mid2记录右边界，这样就满足时间复杂度
### 代码

```golang
func searchRange(nums []int, target int) []int {
    left,right:=0,len(nums)-1
    low,high:=0,len(nums)-1
    fl,fr:=-1,-1
    f1,f2:=false,false

    for (f1==false || f2==false) && (left<=right || low<=high){
        mid1:=(left+right)/2
        mid2:=(low+high)/2
        if f1==false{
            if nums[mid1]<target {
                left=mid1+1
            }else if nums[mid1]>target{
                right=mid1-1
            }else{  //nums[mid]==target
                if mid1 == 0 || nums[mid1-1]!=target{
                    f1=true
                    fl=mid1
                }else{
                    right=mid1-1
                }
            }
        }

        if f2==false{
            if nums[mid2]<target{
                low=mid2+1
            }else if nums[mid2]>target{
                high=mid2-1
            }else{
                if mid2==len(nums)-1 || nums[mid2+1]!=target{
                    f2=true
                    fr=mid2
                }else{
                    low=mid2+1
                }
            }
        }
    }

    return []int{fl,fr}
}
```