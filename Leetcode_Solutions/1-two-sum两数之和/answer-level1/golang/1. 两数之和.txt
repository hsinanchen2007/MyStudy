### 解题思路
1、提升算法效率，所以让算法空间复杂度提升、借助MAP
2、特别需要注意的是，如果遇到目标值跟数组元素是两倍关系的时候，在数组和MAP遍历的时候休要规避

### 代码

```golang
func twoSum(nums []int, target int) []int {
    tmpMap := make(map[int]int)
    result := []int{}
    for key, val := range nums {
        tmpMap[val] = key
    }
    for key1, val1 := range nums {
        if key2, isOk := tmpMap[target - val1]; isOk {
            if key1 == key2 {
                continue
            }
            result = append(result , key1,  key2)
            return result
        }
    }
    return result
}





```