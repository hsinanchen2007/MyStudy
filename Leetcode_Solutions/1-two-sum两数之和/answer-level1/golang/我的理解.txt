### 解题思路
目的：获取和为target的两数下标
对map方式解题的理解：循环遍历数组，声明一个map存放当前数组值（k）和下标(v)，判断target和当前数组值之差是否再map中存在，如果存在返回map的value和当前数组的下标，如果不存在将当前遍历的数组值和下标放到map中。

### 代码

```golang
func twoSum(nums []int, target int) []int {
    var mapDif = make(map[int]int)
    for i, num := range nums{
        if k, ok := mapDif[target-num];ok{
            return []int{k, i}
        }
        mapDif[num] = i
    }
    return nil
}
```