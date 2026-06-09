### 解题思路
代码中注释

### 代码

```golang
func search(nums []int, target int) int {

    var i int 
    var j int
    var lenght=len(nums)-1
    if len(nums)==0{//输入数组为空的时候，返回-1
        return -1
    }
    if nums[i]<nums[lenght] && nums[i]<=target && nums[lenght]>=target{//这个数组没有旋转，按照升序输入
        for i<= lenght{
            if nums[i]==target{
                return i
            }
            i++
        }

        return -1
    }
    //在未知位置进行了旋转，找出旋转的位置最大值和最小值的下标i和j
    for i<len(nums)-1{
        j=i+1

        if nums[j]<=nums[i]{

            break
        }
        i++
    }

    if nums[0]>target && nums[lenght]<target{//判断target是否在这个旋转数组队列中，否的话返回-1

        return -1
    }else if nums[i]>=target && nums[0]<=target {//判断是否在前面数组中，若是在的话循环前半段的数组
        
        for i>=0{
            
            if nums[i]==target{
                return i
            }
            i--
        }

    }else{//上面情况都不存在，那么只有最后一种情况，target在后半段数组中
        for j<=lenght{
            if nums[j]==target{
                return j
            }
            j++
        }

    }
    
    return -1
}
```