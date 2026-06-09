/**
思路：用一个字典{5:0,10:0}保存我们手里5块钱的个数和10块钱的个数。遍历bills时，如果是10，则看m[5]的值是否大于零，如果是20，优先使用10+5,没有10才使用5+5+5
*/
func lemonadeChange(bills []int) bool {
	m := map[int]int{5: 0, 10: 0}
	for _, x := range bills {
		switch x {
		case 5:
			m[5]++
		case 10:
			if m[5] >= 1 {
				m[5]--
				m[10]++
			} else {
				return false
			}
		case 20:
			if m[10] >= 1 {
				if m[5] >= 1 {
					m[10]--
					m[5]--
				} else {
					return false
				}
			} else {
				if m[5] >= 3 {
					m[5]--
					m[5]--
					m[5]--
				} else {
					return false
				}
			}
		}
	}
	return true
}