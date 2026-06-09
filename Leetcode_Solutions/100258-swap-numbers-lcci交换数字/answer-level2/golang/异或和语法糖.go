### 代码

注意这种方式其实也是加了个变量哦
```golang
func swapNumbers(numbers []int) []int {
    numbers[0], numbers[1] = numbers[1], numbers[0]
	return numbers
}
```

```golang
func swapNumbers(numbers []int) []int {
	numbers[0] ^= numbers[1]
	numbers[1] ^= numbers[0]
	numbers[0] ^= numbers[1]
	return numbers
}
```