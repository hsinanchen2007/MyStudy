### 解题思路
![Selection_008.png](https://pic.leetcode-cn.com/969570b0428a980f31baf6745f6af50bd8ac80ae5bef97484f15431fc9da4b05-Selection_008.png)
Go给的函数签名有点坑，用的是int类型而不是int32。int类型对于不同的机器是不一样的，64位机器等价于int64,32位机器等价于int32。

而leetcode后台运行环境显然是64位的，结果导致该溢出的时候没有溢出。
解决方法虽不优雅，但也简单，就是把int类型转换为int32来计算，最后再转回int类型。

其实可说的就只有一点：如何判断溢出。
在没有溢出的情况下，乘除是可逆运算，而溢出时，乘除是不可逆的。
b=k*a(k≠0)
若a≠k/b，则b已溢出

### 代码

```golang
func reverse(x int) int {
	if x < 10 && x > -10 {
		return x
	}
	var flag bool
	var int32X int32
	if x < 0 {
		flag = true
		int32X = -int32(x)
	} else {
		int32X = int32(x)
	}

	var reverseX, remainder, temp int32
	for ;int32X!=0;int32X/=10{
		remainder = int32X%10
		temp = 10*reverseX + remainder
		if reverseX != (temp - remainder)/10 {
			//overflow
			return 0
		}
		reverseX = temp
	}

	if flag {
		return -int(reverseX)
	}
	return int(reverseX)
}
```