关于异或需要了解的：
- a ^ a = 0
- a ^ 0 = a
即任何数与自己异或，得到的结果为0；任何数与0异或，得到的结果为自己本身。
知道了上面的知识我们就可以解决本题了。
假设numbers[0]为a，numbers[1]为b
第一步：我们先将a与b异或放在numbers坐标为0的位置，即
```
numbers[0] = numbers[0] ^ numbers[1]
```
这一步做完之后，numbers数组如下：
[a^b, b]
第二步：
因为 a ^ b ^ b = a ^ 0 = a，所以我们将numbers[0]与numbers[1]异或，放在numbers坐标为1的位置，即
```
numbers[1] = numbers[0] ^ numbers[1]
```
这一步做完之后，numbers数组如下：
[a^b, a]
第三步：
因为 a ^ b ^ a = b ^ a ^ a = b ^ 0 = b，所以我们将numbers[0]与numbers[1]异或，放在numbers坐标为0的位置，即
```
numbers[0] = numbers[0] ^ numbers[1]
```
这一步做完之后，numbers数组如下：
[b, a]
经过这三步之后，我们就完成了本题，完整代码如下：
```
func swapNumbers(numbers []int) []int {
	if len(numbers) != 2 {
		return numbers
	}

	numbers[0] = numbers[0] ^ numbers[1]
	numbers[1] = numbers[0] ^ numbers[1]
	numbers[0] = numbers[0] ^ numbers[1]

	return numbers
}
```

