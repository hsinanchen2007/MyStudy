### 解题思路
括号匹配通常用栈来解决：
遇到左括号入栈，
遇到有括号则出栈。
当前栈的高度即为括号嵌套深度。
我们把嵌套的栈按深度奇偶分别分成两组，即可获得嵌套深度最小的两个括号序列。

### 代码

```golang
func maxDepthAfterSplit(seq string) []int {
    size := len(seq)
    res := make([]int, size)
    //由于栈内只有左括号，我们用一个整型来表示当前栈高度即可，不必实现一个完整的栈。
    depth := 0
    for i := 0; i < size; i++ {
        if seq[i] == '(' {
            depth++
            res[i] = depth % 2
        } else {
            res[i] = depth % 2
            depth--
        }
    }
    return res
}
```