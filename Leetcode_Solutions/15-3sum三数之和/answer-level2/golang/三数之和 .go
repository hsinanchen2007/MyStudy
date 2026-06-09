### 解题思路
该解法性能不咋样

### 代码

```golang
import "sort"

func threeSum(nums []int) [][]int {
    var result [][]int
    var hash map[int][]int = make(map[int][]int)
    for pos, val := range nums {
        hash[val] = append(hash[val], pos)
    }
    var resultMap map[string][]int = make(map[string][]int)
    var filterMap map[string]bool = make(map[string]bool)
    for i := 0; i < len(nums); i++ {
        for j := i + 1; j < len(nums); j++ {
            filterKey := strconv.Itoa(nums[i]) + "_" + strconv.Itoa(nums[j])
            if _, exist := filterMap[filterKey]; exist {
                continue
            }
            val := 0 - nums[i] - nums[j]
            itemArr, exist := hash[val]
            if exist == false {
                continue
            }  else {
                filterMap[filterKey] = true
                for _, k := range itemArr {
                    if k > j {
                        var tmpArr = []int{nums[i], nums[j], nums[k]}
                        key, tmpArr := sortResult(tmpArr)
                        resultMap[key] = tmpArr
                    }
                }
            }
        }
    }
    for _, val := range resultMap {
        result = append(result, val)
    }
    return result
}

func sortResult(arr []int) (string, []int) {
    sort.Ints(arr)
    key := ""
    for i := 0; i < len(arr); i++ {
        key += strconv.Itoa(arr[i])
        key += "_"
    }
    return key, arr
}
```