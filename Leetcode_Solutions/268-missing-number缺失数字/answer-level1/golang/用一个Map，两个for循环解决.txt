### 解题思路
声明一个`map`，然后从0开始遍历`map`，在`map`里找出缺失的数字。

### 代码

```golang
func missingNumber(nums []int) int {
    nummap := make(map[int]bool)
    //将nums数组里的每个数字都存进map里
    for _,num := range nums {
        nummap[num] = true
    }
    //从0开始，在map里遍历，如果没找到，那就是缺失的数字，否则返回-1
    for i:=0;i<len(nums)+1;i++ {
        if !(nummap[i]) {
            return i
        }
    }

    return -1
}
```