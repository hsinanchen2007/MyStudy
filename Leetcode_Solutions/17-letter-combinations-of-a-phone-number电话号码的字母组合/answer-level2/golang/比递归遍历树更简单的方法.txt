本题主流做法是，把各个数字对应的字母，看成不同层级的树的节点，递归遍历即可
个人经验，所有树的递归，都可以拆，变成循环搞定，本题也是

仔细观察每个数字对应的字符 在结果中的重复规律，
每个数都有一个重复周期 即 循环步长，只要确定这个，就可以直接往结果中写元素

![image.png](https://pic.leetcode-cn.com/6569bf98cbb6adbca4bf67f7420e7727124c24e91fdc3d751dee36f310e64634-image.png)

```
func letterCombinations(digits string) []string {
	if len(digits) == 0 {
		return []string{}
	}

	allChars := [][]string{{"a", "b", "c"}, {"d", "e", "f"},
		{"g", "h", "i"}, {"j", "k", "l"}, {"m", "n", "o"},
		{"p", "q", "r", "s"}, {"t", "u", "v"}, {"w", "x", "y", "z"},
	}

	step := 1
	for _, digit := range digits {
		chars := allChars[digit-'2']
		step *= len(chars)
	}
	r := make([]string, step, step)

	for _, digit := range digits {
		chars := allChars[digit-'2']
		step /= len(chars)
		x := 0
		for x < len(r) {
			for _, char := range chars {
				for i := 0; i < step; i++ {
					r[x] += char
					x++
				}
			}
		}
	}

	return r
}
```
