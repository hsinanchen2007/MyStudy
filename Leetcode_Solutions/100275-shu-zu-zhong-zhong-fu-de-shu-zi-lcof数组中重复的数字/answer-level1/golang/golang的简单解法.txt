### 解题思路
    单纯的把数值添加到map，其中map的key使用数字来填充，map的value则是该数字出现的次数

### 代码

```golang
func findRepeatNumber(nums []int) int {
    map_nums := make(map[int]int, len(nums))

    for _, v := range nums{
        map_nums[v]+=1
    }

    for i, v := range map_nums {
        if v > 1 {
            return i
        }
    }

    return -1
}
```