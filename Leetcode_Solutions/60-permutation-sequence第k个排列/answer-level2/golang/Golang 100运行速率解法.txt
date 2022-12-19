**原理就是通过每个层级节点可产生的可能性和k进行比较，找出在每一层需要选择哪个**


```
func getPermutation(n int, k int) string {
    var result = ""
    if n == 0 {
        return result
    }
    var numSet = make([]int, n)
    for i := 0; i < n; i++ {
        numSet[i] = i + 1
    }
    var factorArr = make([]int, n)
    factorArr[0] = 1
    for i := 1; i < n; i++ {
        factorArr[i] = factorArr[i - 1] * i
    }
    var total = 0
    for level := 1; level <= n; level++ {
        //获取在这一层的时候，应该选择数字的索引
        var index = int(math.Ceil(float64(k - total)/float64(factorArr[n - level]))) - 1
        //将前面排除掉的可能性进行去除
        total = total + (index) * factorArr[n - level]
        result += string(numSet[index] + '0')
        //将这个数字从数组中去除
        if index + 1 < len(numSet) {
            numSet = append(numSet[0:index], numSet[index + 1 :]...)
        } else {
            numSet = numSet[0:index]
        }
        
    }
    return result
}
```
