
1. 从头遍历串，将i指针定到 字符串中数字 的 __最高位__：
    - 遇到 +或-，则其下一位作为 int32 的 __最高位__，终止遍历；
    - 遇到数字，则其作为 int32 的 __最高位__，终止遍历；
    - 遇到 空格，跳过考虑下一位；
    - 其它情况，直接返回0。
2. 从 int32 的最高位索引开始遍历串：当遇到非数字，终止遍历，将j指针定到 字符串中数字 的 __最低位__ 的右边。
3. 此时我们已经知道int32的 __最高位__ 和 __最低位__ 的索引。只需要累加起来就得到结果，注意：__当遇到overflow时，返回边界值__。

- 时间复杂度： O(n)
- 空间复杂度： O(1)

```go
const (
    int32Max = 1<<31 - 1
    int32Min = -1 << 31
)

func myAtoi(str string) int {
    n := len(str)
    var i, j int
    neg := false
    for i = 0; i < n; i++ {
        if str[i] >= '0' && str[i] <= '9' {
            break
        } else if str[i] == '+' {
            i++
            break
        } else if str[i] == '-' {
            neg = true
            i++
            break
        } else if str[i] != ' ' {
            return 0
        }
    }
    for j = i; j < n; j++ {
        if str[j] < '0' || str[j] > '9' {
            break
        }
    }
    ret := 0
    for k := i; k < j; k++ {
        cur := int(str[k] - '0')
        if !neg {
            ret = ret*10 + cur
            if ret > int32Max {
                return int32Max
            }
        } else {
            ret = ret*10 - cur
            if ret < int32Min {
                return int32Min
            }
        }
    }
    return ret
}
```

- 执行用时 : 0 ms, 在String to Integer (atoi)的Go提交中击败了100.00% 的用户
- 内存消耗 : 2.3 MB, 在String to Integer (atoi)的Go提交中击败了55.08% 的用户

![image.png](https://pic.leetcode-cn.com/ea7f136909a9e852f91382c0e9e8247e353c7184c6fb3fb9572adf5c88c29a91-image.png)