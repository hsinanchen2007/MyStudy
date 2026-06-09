### 解题思路
直接上代码

### 代码

```golang
func generate(numRows int) (result [][]int) {
    if numRows == 0 {
        return 
    }
    result = append(result, []int{1})
    if numRows == 1 {
        return 
    }
    result = append(result, []int{1, 1})
    if numRows == 2 {
        return
    }
    for i := 1; i < numRows-1; i++ {
        tmp := []int{}
        for k, v := range result[i] {
            if k == 0 {
                tmp = append(tmp, v)
                continue
            }
            tmp = append(tmp, v + result[i][k-1])
        }
        tmp = append(tmp, 1)
        result = append(result, tmp)
    }
    return
}
```