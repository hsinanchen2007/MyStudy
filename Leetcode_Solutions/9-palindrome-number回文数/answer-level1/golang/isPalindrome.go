### 解题思路
判断整数是否为回文数：
	思路-->
		1、将int的x转换成string
		2、设定字符串index的开始i，末尾j，分别i++, j--
		3、如果i==j,说明比较以进行奇数长度字符串中间数字，直接返回true
		4、如果i>j且xStr[i] == xStr[j]相等，说明比较偶数长度字符串，比较到此成立，返回true
		5、如果比较过程中出现xStr[i] != xStr[j]，说名不是回文数字，返回false

### 代码

```golang
func isPalindrome(x int) bool {
    xStr := strconv.Itoa(x)
	for i:=0;;i++{
		j := len(xStr) -1 -i
		if i == j {
			return true
		}else if i > j && xStr[i] == xStr[j]{
			return true
		}else if xStr[i] != xStr[j] {
			return false
		}
	}
}
```