### 思想
从一个元素（偶数可能是两个元素中间，这里统称为中心元素）开始寻找回文字符串。
1. 寻找中心元素需要的时间代价为O(N)
2. 从该中心元素开始向外扩展去寻找回文字符串，只要碰到一个不符合条件的，辣么就终止寻找。然后与已存的最大长度子串比较长度，若更长就替换。 向外扩展需要的时间代价为O(N)
**最终的时间复杂度：$O(N^2)$**

### 代码
```golang
func longestPalindrome(s string) string {
    max := 0
    longest := ""
    for x := 0; x < len(s); x++ {
        son, l := centerSpread(s, x, x)
        if l > max {
           longest = son 
           max = l
        } 
        son, l = centerSpread(s, x, x+1)
        if l > max {
            longest = son
            max = l
        }
    }
    return longest
}

// @param s 就是辣个字符串
// @param i, j i与j确定中心位置  if i == j then s is 奇数子串
func centerSpread(s string, i, j int) (string, int) {
    var left, right int = i, j
    if i == j {
        left = i - 1
        right = i + 1
    }

    for x := 0; x < len(s) / 2; x++ {
        if left < 0 || right >= len(s) || s[left] != s[right] {
            break
        }
        left--
        right++
    }

    return s[left+1 : right], right-left-1
}

```
### 结果
+ 执行用时 : 8 ms, 在所有 golang 提交中击败了77.67%的用户
+ 内存消耗 : 2.2 MB, 在所有 golang 提交中击败了86.52%的用户
![image.png](https://pic.leetcode-cn.com/17165376f83239f5472a8536708312416c8750a834987b9cd0e11bd726d1e432-image.png)