### 解题思路
Go里面没找到异或Operator，人肉做。
循环右移，判断末位是否不一样，不一样则加一

### 代码

```golang

func hammingDistance(x int, y int) int {
	c := 0
	for i := 0; i < 32; i++ {
		b1, b2 := (x>>i)&1, (y>>i)&1
		if b1 != b2 {
			c++
		}
	}
	return c
}
```