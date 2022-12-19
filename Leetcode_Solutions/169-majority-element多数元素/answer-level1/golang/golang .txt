### 解题思路
此处撰写解题思路

### 代码

```golang
func majorityElement(nums []int) int {
    res := 0
    count := 0
    for i := 0; i<len(nums); i++{
        if res == nums[i]{
            count++
        }else if count == 0{
            res = nums[i]
        }else{
            count--
        }
    }
    return res
}
```