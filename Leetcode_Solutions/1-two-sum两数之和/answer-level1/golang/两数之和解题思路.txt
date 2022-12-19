### 解题思路

我们首先构建一个map， 这个map的key是数组的val， value是该val在数组中的pos。

然后我们遍历整个数组， 查看 target - val是否在map中； 
如果存在，而且dstPos和原Pos不一致。 那么就得到了结果了， 这时候我们就需要返回。 
如果都不存在， 那么就返回空。

### 代码

```golang


func twoSum(nums []int, target int) []int {
    var numMap map[int]int = make(map[int]int)
    var result []int
    for pos, val := range nums {
        numMap[val] = pos
    }
    for pos, val := range nums {
        dstVal := target - val
        dstPos, exist := numMap[dstVal]
        if exist && (dstPos != pos){
            result = append(result, pos)
            result = append(result, dstPos)
            return result
        }
    }
    return result
}


```