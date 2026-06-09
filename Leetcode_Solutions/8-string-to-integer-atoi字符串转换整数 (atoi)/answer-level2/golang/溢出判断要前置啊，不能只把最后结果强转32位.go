### 解题思路
防溢出预判参考第7题反转整数，返回定义的类型是int，在64位平台上它的有效值范围等同于int64，已经超出int32的范围了再判断是否溢出是违背题目初衷的。
为了极致的效率，此处牺牲了点可读性，把math.MaxInt32/10的结果直接算出来放代码里了。
for...range遍历时需要复制值，而且遍历出来的结果是byte，还要string转一下，不如直接for循环。
数字字符串强制转换成数字的做法也不提倡，这里使用一个函数外的map来表示映射关系。

执行用时 :0 ms, 在所有 Go 提交中击败了100.00% 的用户
内存消耗 :2.3 MB, 在所有 Go 提交中击败了60.14%的用户

### 代码

```golang
//假设不允许使用强转，则用一个map来表示字符串数字映射关系
var MapStrInt = map[string]int{"0": 0, "1": 1, "2": 2, "3": 3, "4": 4, "5": 5, "6": 6, "7": 7, "8": 8, "9": 9}

func myAtoi(str string) int {
	flag := 1      // 正负
	res := 0       // 结果
	begin := false // 未开始
	for i := 0; i < len(str); i++ {
		c := str[i : i+1] //等价于 c := string(str[i])
		if n, ok := MapStrInt[c]; ok {
			// 防溢出预判：MaxInt32=2147483647 MinInt32=-2147483648
			if res > 214748364 || res == 214748364 && n > 7 {
				return 2147483647
			}
			if res < -214748364 || res == -214748364 && n > 8 {
				return -2147483648
			}
			res = res*10 + flag*n
			begin = true
		} else {
			if begin {
				break // 开始转换后遇到非数字停止转换
			} else {
				if c == "+" {
					begin = true
				} else if c == "-" {
					flag = -1
					begin = true
				} else if c != " " {
					return 0
				}
			}
		}
	}
	return res
}
```