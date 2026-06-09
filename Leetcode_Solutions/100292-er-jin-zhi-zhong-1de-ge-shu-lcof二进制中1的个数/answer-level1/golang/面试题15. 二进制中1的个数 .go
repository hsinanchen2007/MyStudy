### 解题思路
此处撰写解题思路

### 代码

```golang
func hammingWeight(num uint32) int {
    
    count := 0
    for num > 0 {
        if num&1 == 1 {
            count++
        }
        num = num>>1
    }
    return count
}
```