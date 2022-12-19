
解题思路
最开始想暴力破解，后来准备浏览答案时突然看到提示是值是按顺序排序的，突然想到这是一个突破点。
每一行第一个值是最小的，最后一个值不确定，所以以第一个值为对比，若目标值比第一个值小，则遍历该行，
没有继续下一行，若第一个值大于目标值则不遍历该行，等于则直接返回


```
func findNumberIn2DArray(matrix [][]int, target int) bool {
    firstLen := len(matrix)
    if firstLen == 0 {
        return false
    }
    for i:=0; i<firstLen; i++ {
        secondLen := len(matrix[i])
        if secondLen == 0 {
            return false
        }
        if target > matrix[i][0] {
            for j:=0; j<secondLen; j++ {
                if target == matrix[i][j] {
                    return true
                }else {
                    continue
                }
            }
            continue
        }else if target == matrix[i][0] {
            return true
        }else {
            continue
        }
    }
    return false
}
```
