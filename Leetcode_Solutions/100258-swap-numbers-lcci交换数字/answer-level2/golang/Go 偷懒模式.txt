### 解题思路
此处撰写解题思路

### 代码

```golang
func swapNumbers(numbers []int) []int {
    numbers[0],numbers[1] = numbers[1],numbers[0]
    return numbers
}
```