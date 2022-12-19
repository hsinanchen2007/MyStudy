### 解题思路
target - a = b
target - b = a
将每个值缓存在map中，进行查找

### 代码

```golang
func twoSum(nums []int, target int) []int {
    numMap := make(map[int]int)
    for i := 0; i<len(nums); i++ {
        diff := target - nums[i]
        if i1, ok := numMap[diff]; ok {
            return []int{i1, i}
        }

        numMap[nums[i]] = i
    }
    return []int{}
}
```