### 解题思路
此处撰写解题思路

### 代码

```golang
func majorityElement(nums []int) int {
    res := nums[0]
    time := 0
    for _,v := range nums{
        if res == v {
            time += 1
        }else{
            time -= 1
        }
        if time == 0{
            res= v
            time = 1
        }
    }
    return res
}
```