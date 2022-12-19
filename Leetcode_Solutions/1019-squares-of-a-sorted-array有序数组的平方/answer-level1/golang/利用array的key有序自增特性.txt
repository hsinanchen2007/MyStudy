![深度截图_选择区域_20191128181345.png](https://pic.leetcode-cn.com/d44b3bd49f68998db9a146523c5c5036addbdcdeea6b6c9b1e6690666d7160ed-%E6%B7%B1%E5%BA%A6%E6%88%AA%E5%9B%BE_%E9%80%89%E6%8B%A9%E5%8C%BA%E5%9F%9F_20191128181345.png)

根据题意:
1. 1 <= A.length <= 10000
2. -10000 <= A[i] <= 10000
可得到A[i]的绝对值取值范围在0~10000之间，因此可以利用array的key有序自增特性。
`temp = [10001]int{}`即是估算的入参值的范围，将A[i]的值取绝对值作为temp[A[i]]，有重复，则+1，证明该数字出现过N次。
最后遍历temp，取temp[A[i]]不为0的值(为0表示一次都没出现过)，循环追加temp[A[i]]次进结果数组。


```golang
func sortedSquares(A []int) []int {
    var (
        temp = [10001]int{}
        result []int
    )
    for _, v := range A {
        if v < 0 {
            v = 0 - v
        }
        temp[v] = temp[v] + 1
    }

    for i := 0;i<len(temp);i++{
        if temp[i] == 0 {
            continue
        }
        for j:=0;j<temp[i];j++{
            result = append(result, i * i)
        }
    }
    return result
}
```