### 解题思路
1. 排序后取第一个元素, 遍历 n 次
2. 直接找到第一个比之前的元素小的元素. 最弱会退化到与第一个方法一样

### 代码

```golang []
func minArray(numbers []int) int {
    for i, n := range numbers {
        if i == 0 {continue}
        if n < numbers[i-1] {
            return n
        }
    }
    return numbers[0]
}
```
```golang []
func minArray(numbers []int) int {
    sort.Ints(numbers)
    return numbers[0]
}
```