整数的反转很简单，但是溢出检查需要思考一下
这里提出一个思路：
如果num > max_int / 10，那么num*10后一定溢出，所以此题就简单了

补充：
	在做下一题时，意识到num > max_int / 10，再加上一位也可能溢出
	但是此题不会，因为如果新加的一位 >7 or <-8 的话，原数就溢出了
	考虑不周，但是恰巧没错


![image.png](https://pic.leetcode-cn.com/3951ef70b89f4232e42242e0eb57c9be5b25fe8f21fa0e17ac24b6bb7b479ab6-image.png)

```
func reverse(x int) int {
	var min int = math.MinInt32 / 10
	var max int = math.MaxInt32 / 10
	var y int = 0
	for x != 0 {
		if y < min || y > max {
			return 0
		}
		y = y*10 + x%10
		x = x / 10
	}
	return y
}
```

