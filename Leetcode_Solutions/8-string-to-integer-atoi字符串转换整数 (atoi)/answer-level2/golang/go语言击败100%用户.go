
![1560851569(1).png](https://pic.leetcode-cn.com/45a19f1a981593fdca51e6b0783c6bcd5e0d8a891cee195361c42531b67af26a-1560851569\(1\).png)

step1：去无效字符

step2：规范首字符

step3：遍历检测数字0-9

step4：转换

step5：转换异常处理

```
import (
	"strconv"
	"strings"
)

func myAtoi(str string) int {
	//step1：去无效字符
	str = strings.TrimSpace(str)
	if str == "" || (len(str) == 1 && (str < "0" || str > "9" )){
		return 0
	}
	//step2：规范首字符
	flag := ""
	if string(str[0]) == "-" {
		flag = "-"
		str = str[1:len(str)]
	}else if string(str[0]) == "+" {
		str = str[1:len(str)]
	}
	//step3：遍历检测数字0-9
	resStr := "0"
	for i := 0; i < len(str) ; i++  {
		if string(str[i]) < "0" || string(str[i]) > "9" {
			break
		}
		resStr += string(str[i])
	}
	resStr = flag + resStr
	//step4：转换
	res, err := strconv.ParseInt(resStr, 10, 32)

	const MaxUint = ^uint32(0)
	const MaxInt = int(MaxUint >> 1)
	const MinInt = -MaxInt - 1
	
	//step5：转换异常处理
	if err != nil {
		if flag == "" {
			return MaxInt
		}
		return MinInt
	}

	return int(res)
}
```