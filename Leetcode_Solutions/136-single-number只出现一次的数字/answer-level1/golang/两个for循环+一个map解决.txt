### 解题思路

- 第一步，新建一个`map`，用一个`for`循环，记录`nums`数组中出现的元素和次数，如果重复出现，`value`置为2，出现一次置为1；
- 第二步，再用一个`for`循环，遍历这个新建`map`，判断`value`为是否1，如果为1，就把`value`为1对应的`key`返回即可。

### 代码

```golang
func singleNumber(nums []int) int {
    numsmap := make(map[int]int)
    var result int
    for _,v := range nums {
        if numsmap[v] != 0 {
            numsmap[v] = 2
        } else {
            numsmap[v] = 1
        }

    }
    for k,v := range numsmap {
        if v == 1 {
            result = k
        }
    }

    return result
}
```