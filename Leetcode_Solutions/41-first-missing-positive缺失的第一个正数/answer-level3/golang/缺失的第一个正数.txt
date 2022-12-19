### 解题思路
注释于代码中

### 代码

```golang
func firstMissingPositive(nums []int) int {
    sort.Ints(nums)//先从小到大排序，不想写一个排序算法，直接引用
    var flag=true //判断数组中是否有1
    var flag1=false//判断是否进入相邻数组的比较，得到结果
    var res int
    for i:=0;i<=len(nums)-1;i++{//nums的长度大于等于2才进入判断
        if nums[i]==1{
            flag=false //数组中有1的话，为false
        }

        if  i+1<len(nums) && nums[i+1] != nums[i]{//若是0，1，1，3，3这样的情况，相邻两个数不相等，进入下一步的判断
            if nums[i+1] !=nums[i]+1 && nums[i]+1>0 { //0，1，{1，3}，3括号中的两个数字不相等，则取最小值+1
                flag1=true
                res=nums[i]+1
                break
            }
            
        }

    }
    if len(nums)==1 && nums[0]>1{// 长度为1时且大于数组内的值大于1时，得到结果
        return 1
    }else if len(nums)==1 && nums[0]==1{//这时针对nums={1}的情况得到的结果
        return nums[len(nums)-1]+1
    }
    if flag{
        
        return 1
    }

    if flag1{
        return res
    }
    

   
    return nums[len(nums)-1]+1  //如果上面都不成立，则只有一种情况就是0，1，1，2，3这种中间不缺少最少正整数的，取nums最后一个数+1

}
```