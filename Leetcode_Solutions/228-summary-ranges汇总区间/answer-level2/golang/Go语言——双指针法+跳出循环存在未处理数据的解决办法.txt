### 解题思路
本题使用双指针法，思路是不难想到的，但是需要处理两个细节。
(1)数组为空时的判断
(2)跳出循环时有未处理的数据
解决这两种做法的方式是：在nums中添加一个不连续的数据，比如nums[0]-1

### 代码

```golang
func summaryRanges(nums []int) []string {
    res:=[]string{}
    
    if len(nums)<=0{
        return res
    }
    nums=append(nums,nums[0]-1)
    
    left,right:=0,1
    for right<len(nums){
        if nums[right]-nums[right-1]!=1{
            var str string
            if right-left>1{
                str=strconv.Itoa(nums[left])+"->"+strconv.Itoa(nums[right-1])
            }else{
                str=strconv.Itoa(nums[left])
            }
            
            res=append(res,str)
            left=right           
        }
        right++
    }

    // var s string 
    // if right-left==1{
    //     s=strconv.Itoa(nums[left])     
    // }else{
    //     s=strconv.Itoa(nums[left])+"->"+strconv.Itoa(nums[right-1])
    // }
    // res=append(res,s)

    return res
}
```