找到最大的数字，然后遍历

当然还可以结合分片来提高效率，然后合并slice。


```golang
func printNumbers(n int) []int {
    if n <= 0 {
        return []int{}
    }
    endNum := int(math.Pow10(n)) - 1

    result := make([]int, endNum)
    for i := 0; i < endNum; i++ {
        result[i] = i + 1
    }

    return result
}
```