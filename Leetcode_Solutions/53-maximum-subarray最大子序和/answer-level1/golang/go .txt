### 解题思路
此处撰写解题思路

### 代码

```golang
func maxSubArray(nums []int) int {
    if len(nums)<1{
        return 0
    }
    max1:=nums[0]
    for i:=1;i<len(nums);i++{
       if nums[i-1]>0{
           nums[i]+=nums[i-1]
          
       }
        if max1<nums[i]{
               max1=nums[i]
           }
    }
    return max1
}
```