思路：利用递归获取上一列表的值，获取值后，再用for依次对期切片的索引赋值。(ps:空间复杂度还有待优化)
```
func getRow(rowIndex int) []int {
    //f(i,j) = f(i-1,j-1) + f(i-1,j)
    patr := make([]int,rowIndex+1)
    if rowIndex == 0 {
        patr[0] =1
    }else {
         patr[0],patr[rowIndex] = 1,1
         result := getRow(rowIndex-1)
         for i := rowIndex-1;i>=1;i-- {
         patr[i] = result[i-1] + result[i]
        }
    }
    return patr
}
```
