### 解题思路

双指针法，从末位开始依次相加，temp存储相加后的和，carry为进位，把temp%10依次加到结果的头部，最后再判断一下carry，如果是1，说明最后一次运算有进位，也要算上。

### 代码

```golang
func addStrings(num1 string, num2 string) string {
	i,j,carry,temp := len(num1)-1,len(num2)-1,0,0
	res := ""
	var n1,n2 int
	for i >= 0 || j >= 0 {
		if i >= 0 {
			n1 = int(num1[i]-'0')
		}else {
			n1 = 0
		}
		if j >= 0 {
			n2 = int(num2[j]-'0')
		}else {
			n2 = 0
		}
		temp = n1 + n2 + carry
		carry = temp / 10
		res = fmt.Sprintf("%d%s",temp%10,res)
		i--
		j--
	}
	if carry == 1 {
		res = fmt.Sprintf("%d%s",carry,res)
	}
	return res
}
```