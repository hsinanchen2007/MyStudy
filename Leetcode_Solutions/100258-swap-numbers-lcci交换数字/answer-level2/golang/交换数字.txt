### 解题思路
so easy

### 代码

```golang
func swapNumbers(numbers []int) []int {
    numbers[0], numbers[1] = numbers[1], numbers[0]
    return numbers
}
```