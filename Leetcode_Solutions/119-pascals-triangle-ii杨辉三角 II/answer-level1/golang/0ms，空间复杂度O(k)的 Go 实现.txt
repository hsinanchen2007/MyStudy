
![image.png](https://pic.leetcode-cn.com/2b4bae9e7c5eeacc1088e9386441b0811c49dbf8a205e93051592d8af55756cb-image.png)

实现空间复杂度O(k)的要点在于：在原数组上计算下一行。

代码
```
func getRow(rowIndex int) []int {
    a := []int{1}
    for i:=1; i<=rowIndex; i++ {     // 计算杨辉三角第 rowIndex 行
        for j:=0; j<i-1; j++ {
            a[j] = a[j] + a[j+1]
        }
        t := []int{1}
        a = append(t, a...)
    }
    return a
}
```