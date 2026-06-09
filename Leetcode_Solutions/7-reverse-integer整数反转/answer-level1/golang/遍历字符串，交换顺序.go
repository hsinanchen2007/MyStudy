### 解题思路
先转为字符串，遍历字符串，交换顺序

### 代码

```golang
import "strconv"

func reverse(x int) int {
    var str string
	if x < 0 {
		str = strconv.Itoa(0-x)
	}else {
		str = strconv.Itoa(x)
	}
	r := []rune(str)
	l := len(r)
	var halfLen int
	if l% 2 == 0{
		halfLen = l /2
	}else {
		halfLen = (l-1) /2
	}
	for i,_ := range r {
		if i == halfLen {
			break
		}
		tmp := r[i]
		r[i] = r[l-i-1]
		r[l-i-1] = tmp
	}
	res := string(r)
	if x < 0 {
		res = "-"+res
	}
	intRes,err := strconv.Atoi(res)
	if err != nil{
		return 0
	}
	if intRes > 1 << 31 -1 || intRes < -1 << 31 {
		return 0
	}
	return intRes
}
```