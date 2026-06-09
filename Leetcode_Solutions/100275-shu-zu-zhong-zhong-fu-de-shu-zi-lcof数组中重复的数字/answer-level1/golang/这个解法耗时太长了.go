### 解题思路
用 map 把数组里的数字存进去，同时能统计次数，但是有两个循环，花费的时间太长了，找找看别人的方法

### 代码

```golang
func findRepeatNumber(nums []int) int {
    var tmp = make(map[int]int);
    var ans int
    for i := 0; i < len(nums); i++ {
        tmp[nums[i]]++;
    }
    for k,v := range tmp{
        if (v > 1){
            ans = k;
            break;
        }
    }
    return ans;
}
```