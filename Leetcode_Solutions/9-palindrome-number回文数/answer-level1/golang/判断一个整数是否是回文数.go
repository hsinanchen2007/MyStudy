### 思路
将数字转化成字节数组，然后数组元素低位和高位一一比对
### 完整代码
```
	smallsString := "00010203040506070809" +
		"10111213141516171819" +
		"20212223242526272829" +
		"30313233343536373839" +
		"40414243444546474849" +
		"50515253545556575859" +
		"60616263646566676869" +
		"70717273747576777879" +
		"80818283848586878889" +
		"90919293949596979899"

	if x < 0 {
		return false
	}
	if x < 10 {
		return true
	}
	var a [10]byte // int类型非负整数 最大长度为10位
	i := 10
	us := x
	for us >= 100 {
		is := us % 100 * 2
		us /= 100
		i -= 2
		a[i+1] = smallsString[is+1]
		a[i+0] = smallsString[is+0]
	}
	// us < 100
	is := us * 2
	i--
	a[i] = smallsString[is+1]
	if us >= 10 {
		i--
		a[i] = smallsString[is]
	}
	begin := i
	end := 9
	for begin < end {
		if a[begin] != a[end] {
			return false
		}
		begin++
		end--
	}
	return true
```
### 执行结果
![image.png](https://pic.leetcode-cn.com/9b5f5630eab5b0e49e4d7f21be4bb81fd9b624f07ed9e5c65a756e4432d94c12-image.png)
