### 解题思路
位运算：与、位移

### 代码

```golang
func hammingWeight(num uint32) int {
    res := 0
    for num > 0 {

        if num & 1 == 1 {
            res++
        }
        num = num >> 1
    }
    return res
}
```