### 解题思路

1，建立一个key为int，value为bool的map  
2，range数组nums里的每一个元素，并查询第一步建立的map，如果map中没有这个值，就将num存进map，并将它的value置为true；
3，因此当遍历出map中已经存在的数字时，就代表这个数组已经出现了重复数字，直接返回这个num。

### 代码

```golang
func findRepeatNumber(nums []int) int {
    var nummap = make(map[int]bool)
    for _,num := range nums {
        if !nummap[num] {
            nummap[num] = true
        } else {
            return num
        }
    }

    return -1
}
```