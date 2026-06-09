### 解题思路

数组元素作为 key；次数为 value

遍历数组，将 （key, value++）存入哈希表，并判断 value 的值是否超过数组长度的一半。如果超过，即返回元素即可。

### 代码

```golang
func majorityElement(nums []int) int {
    res := make(map[int]int)
    for _, m := range nums {
        res[m]++
        if res[m] > len(nums) >> 1 {
            return m
        }
    }
    return 0
}
```