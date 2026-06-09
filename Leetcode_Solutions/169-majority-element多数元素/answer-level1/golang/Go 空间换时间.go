### 解题思路
此处撰写解题思路

### 代码

```golang
func majorityElement(nums []int) int {
    var count = make(map[int]int,0)
    var lens = math.Floor(float64(len(nums))/2) 
    for _,v := range nums{
        count[v] += 1
        if float64(count[v]) > lens{
            return v
        } 
    }
    return -1
}
```