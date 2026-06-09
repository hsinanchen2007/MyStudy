### 解题思路

亦或之后求1的个数，调用math/bits包的函数即可统计1的个数，一行代码直接实现。

### 代码

```golang
func hammingDistance(x int, y int) int {
	return bits.OnesCount(uint(x) ^ uint(y))
}
```