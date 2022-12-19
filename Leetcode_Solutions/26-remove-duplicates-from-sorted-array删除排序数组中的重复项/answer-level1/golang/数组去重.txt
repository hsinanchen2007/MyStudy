### 代码

```golang
func removeDuplicates(nums []int) int {
    var k,index int
    if len(nums)==0{
        return 0
    }
    k,index=nums[0],1
    for i:=1;i<len(nums);i++{
        if nums[i]!=k{
            k=nums[i]
            nums[index]=nums[i]
            index++
        }
    }
    return index
}
```