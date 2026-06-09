## 结果

![image.png](https://pic.leetcode-cn.com/ccc3b9f67177e42c3e5d39d1128f6b9d15f5d42395b9d2200899407a24c009fb-image.png)

## 思路

根据定义，第1（从0开始）行以后应该生成i+1个数的数组，数组首末都为1，再把上一行的对应位置上的数相加即可


```
func generate(numRows int) [][]int {
    if numRows == 0 {
        return [][]int{}
    }
    result := [][]int{
        {1},
    }
    for i:=1;i<numRows;i++ {
        if i == 0 {
            result = append(result, []int{1})
        }
        row := make([]int, i+1)
        row[0] = 1
        row[i] = 1
        for j:=0;j<len(result[i-1])-1;j++ {
            row[j+1] = result[i-1][j] + result[i-1][j+1]
        }
        result = append(result, row)
    }
    return result
}
```
