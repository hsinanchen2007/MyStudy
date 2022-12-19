### 解题思路
每次和1求与运算，如果等于1则表示最后一位为1,然后向右移一位，直到num为0

### 代码

```golang
func hammingWeight(num uint32) int {
    count := 0 
    for num != 0 {
        if num & 1 == 1 {
            count++
        }
        num >>= 1
    }
    return count
}
```