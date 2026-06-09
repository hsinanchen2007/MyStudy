### 解题思路

- 1，通过`for range`语句遍历`nums`数组里的每一个元素  
- 2，声明一个`int`型变量`count`，用来记录**其中位数为 偶数 的数字的个数**  
- 3，通过`len`获取元素长度，然后看是否可以被2整除，如果可以，则将`count`+1，等`for range`遍历结束，返回`count`即可。

### 代码

```golang
func findNumbers(nums []int) int {
    count := 0
    for _,value := range nums {
        if len(strconv.Itoa(value)) % 2 == 0 {
            count++
        }
    }
    
    return count
}
```