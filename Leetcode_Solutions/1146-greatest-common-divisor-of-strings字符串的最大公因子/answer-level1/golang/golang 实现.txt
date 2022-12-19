### 解题思路
先算出gcd的长度，即str1和str2的长度经过辗转相除后得到的剩余长度，判断长度是否满足为str1和str2的长度的公约数，然后再逐项判断每个byte是否一致。
### 代码

```golang
func gcdOfStrings(str1 string, str2 string) string {
	gcd_len := calgcd(str1, str2)
	if len(str1)%gcd_len != 0 || len(str2)%gcd_len != 0 {
		return ""
	}
	gcd := str1[len(str1)-gcd_len:]
	for i := 0; i < len(str1); i += gcd_len {
		for j := 0; j < gcd_len; j++ {
			if gcd[j] != str1[i+j] {
				return ""
			}
		}
	}
	for i := 0; i < len(str2); i += gcd_len {
		for j := 0; j < gcd_len; j++ {
			if gcd[j] != str2[i+j] {
				return ""
			}
		}
	}
	return gcd
}

func calgcd(str1, str2 string) int {
	l1, l2 := len(str1), len(str2)
	if l1 < l2 {
		l1, l2 = l2, l1
	}
	for l2 != 0 {
		l1, l2 = l2, l1-l1/l2*l2
	}
	return l1
}

```