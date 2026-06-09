### 解题思路
**把 string 转换为 []byte 判断。**
1. 预处理字符
	1. 清理空格
	2. 判断是否为空
2. 首字符处理
	1. **过滤首字符，后续当做正数处理**
3. 转为 []byte
	1. 根据 ascii 码，判断是否是数字
	2. 判断是否溢出，溢出后返回值为 「最大正数+1」
4. 根据首字符做**符号和范围的修正**
	

### 代码

```golang
func myAtoi(str string) int {
    str = strings.TrimSpace(str)

	if len(str) == 0 {
		return 0
	}

	// 保留符号的 str
	s0 := str
	// 过滤符号
	if str[0] == '-' || str[0] == '+' {
		str = str[1:]
	}

	// 声明返回值
	n := 0
	for _, b := range []byte(str) {
		b -= '0'
		// 不是数字
		if b > 9 {
			break
		}
		n = n*10 + int(b)
        // 判断边界
        if n > 2147483647 {
            // 表示已溢出
            n = 2147483648
            break;
        }
	}
	// 判断符号 && 边界
	if s0[0] == '-' {
		n = -n
	}else if n >= 2147483648 {
        // 修正正数范围
        n = 2147483647
    }

	return n
}
```