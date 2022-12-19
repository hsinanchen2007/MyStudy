### 解题思路
（p.s.自己也是够笨的了，我发现了我的问题，好像没有算法的思想，就是看见一个题不知道怎么弄
是做的题太少吧，自己每次的解题思路都是最笨的办法，而且有时候还解不出来，我天）

### 代码

```golang
func massage(nums []int) int {
	a, b := 0, 0
	for i := 0; i < len(nums); i++ {
		c := Max(b, a+nums[i])
		a = b
		b = c
	}

	return b
}

func Max(i, j int) int {
	if i > j {
		return i
	}
	return j
}
```