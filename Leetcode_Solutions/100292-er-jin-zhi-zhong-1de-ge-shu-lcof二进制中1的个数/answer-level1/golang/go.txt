执行用时 :
0 ms
, 在所有 Go 提交中击败了
100.00%
的用户
内存消耗 :
2 MB
, 在所有 Go 提交中击败了
100.00%
的用户

```
func hammingWeight(num uint32) int {
    count := 0
    for num > 0 {
        if num % 2 == 1 {
            count++
        }
        num = num >> 1
    }
    return count
}
```
