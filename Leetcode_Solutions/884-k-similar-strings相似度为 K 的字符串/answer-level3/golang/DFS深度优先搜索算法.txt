### 解题思路
比较A[i]与B[i], 然后找到可以交换一次的位置，找不到就找交换一次但是需要换回来的

### 代码

```golang
func kSimilarity(A string, B string) int {
    strA := []byte(A)
    strB := []byte(B)
    var min = 1<<31
    var dfs =func(tp, k int, strA, strB []byte) {}
    dfs = func(tp, k int, strA, strB []byte) {
        // 调整完成
        if string(strA) == string(strB) {
            // 最小的调整次数
            if tp < min {
                min = tp
            }
            return
        }
        // 当前位置相等
        if strA[k] == strB[k] {
            dfs(tp, k + 1, strA, strB)
        } else {
            temp := strA[k]
            // 从后面开始找
            for i := k + 1; i < len(strB); i++ {
                // 找到可以交换1次的字符
                if strB[i] == temp && strA[i] == strB[k] {
                    // 找到了就交换A
                    strA[i], strA[k] = strA[k], strA[i]
                    tmp := make([]byte, len(strA))
                    copy(tmp, strA)
                    // 交换次数加一，游标前进
                    dfs(tp + 1, k + 1, tmp, strB)
                    return
                }
            }
            for i := k + 1; i < len(strA); i++ {
                // 找到A中和B[k]相等的字符，交换递归，再换回去，深度优先
                if strA[i] == strB[k] {
                    strA[i], strA[k] = strA[k], strA[i]
                    tmp := make([]byte, len(strA))
                    copy(tmp, strA)
                    dfs(tp + 1, k + 1, tmp, strB)
                    strA[i], strA[k] = strA[k], strA[i]
                }
            }
        }
    }
    dfs(0, 0, strA, strB)
    return min
}


```