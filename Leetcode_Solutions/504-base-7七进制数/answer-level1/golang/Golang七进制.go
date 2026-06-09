### 解题思路
用uint8的slice存数字，然后把slice反转一下，然后转换成string

### 代码

```golang
func convertToBase7(num int) string {
	if num < 0 {
		return "-" + convertToBase7(-num)
	}
    if num == 0 {
        return "0"
    }
	var ans []uint8
	for num != 0 {
		ans = append(ans, uint8('0'+num%7))
		num /= 7
	}
	reverseUint8Slice := func(data []uint8) []uint8 {
		for i := 0; i < len(data)>>1; i++ {
			data[i], data[len(data)-i-1] = data[len(data)-i-1], data[i]
		}
		return data
	}
	return string(reverseUint8Slice(ans))
}

```