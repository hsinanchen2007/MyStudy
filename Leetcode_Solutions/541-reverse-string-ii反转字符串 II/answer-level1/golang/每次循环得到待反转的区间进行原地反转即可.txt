### 解题思路
执行用时 :0 ms, 在所有 Go 提交中击败100.00%的用户
内存消耗 :3.5 MB, 在所有 Go 提交中击败了100.00%的用户

每次循环得到待反转的区间进行原地反转即可

### 代码

```golang
func reverseStr(s string, k int) string {
    bytes := []byte(s)
    l := len(bytes)
    left:=0
    for i := 0 ; left < l; i++ {
        left = i*2*k // 每次，待反转的左边界
        right := left + k - 1 // 每次，待反转的右边界
        if right > l - 1 {
            right = l - 1
        } 
        for left < right {
            bytes[left],bytes[right] = bytes[right],bytes[left]
            left +=1
            right -=1
        }
    }
    return string(bytes)
}
```