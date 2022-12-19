### 解题思路
我刚开始在代码起始部分，加了一个判断后面是否有0的判断，就报超时，但是把那个删了，这个执行用时0ms，就比较厉害了。
题目中说了，电脑机器32位的，所以直接弄一个64位的数去存储计算，然后和32位的去判断，最后返回结果（记得转换为Int型）。

### 代码

```golang
func reverse(x int) int {
	var x64 int64 = int64(x)
	var res int64 = x64 % 10
	x64 = x64 / 10
	for x64 != 0 {
		res = res * 10 + x64 % 10
		x64 = x64 / 10
	}
	if res>math.MaxInt32 || res <math.MinInt32 {
		return 0
	}
	return int(res)
}
```