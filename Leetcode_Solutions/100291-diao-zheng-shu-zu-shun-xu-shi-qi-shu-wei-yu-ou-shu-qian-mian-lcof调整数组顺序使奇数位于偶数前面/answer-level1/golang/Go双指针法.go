### 代码

```golang
func exchange(nums []int) []int {
    if len(nums)<2{
        return nums
    }
    slow,fast:=0,1
    for{
        for fast<len(nums){
            if nums[fast]%2!=0{
                break
            }
            fast++
        }
        for slow<fast{
            if nums[slow]%2==0{
                break
            }
            slow++
        }
        if fast>=len(nums){
            break
        }else if slow!=fast{
            t:=nums[slow]
            nums[slow]=nums[fast]
            nums[fast]=t
        }else{
            fast++
            slow++
        }
    }
    return nums
}
```