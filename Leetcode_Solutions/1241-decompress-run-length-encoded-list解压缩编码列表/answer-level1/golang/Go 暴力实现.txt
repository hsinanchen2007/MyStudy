### 解题思路

### 代码

```golang
func decompressRLElist(nums []int) []int {
    var i int
    var List []int
    for i < len(nums){
        List = append(List,Unzip(nums[i],nums[i+1])...)
        i += 2
    }
    return List
}

func Unzip(freq, val int) []int{
    var subList []int
    for i:=0;i<freq; i++{
        subList = append(subList,val)
    }
    return subList
}
```