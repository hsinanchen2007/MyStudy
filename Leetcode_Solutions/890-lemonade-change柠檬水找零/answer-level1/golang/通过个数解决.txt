```
/*
遍历数组
出现5，5的个数++
出现10(10-5)，5的个数大于0，5的个数--，10的个数++;5的个数为0，返回false
出现20(20-10-5(优先),或20-5-5-5)，
	10的个数大于0，10的个数个数--，5的个数大于0，5的个数减一，5的个数为0，返回false；
	10的个数为0，5的个数大于等于3，5的个数-3，否则返回false
*/
func lemonadeChange(bills []int) bool {
	perCount := map[int]int{
		5:  0,
		10: 0,
	}
	// 遍历数组
	for _, v := range bills {
		if v == 5 {
			// 出现5，5的个数++
			perCount[5]++
		} else if v == 10 {
			// 出现10(10-5)，5的个数大于0，5的个数--，10的个数++;5的个数为0，返回false
			if perCount[5] > 0 {
				perCount[5]--
				perCount[10]++
			} else {
				return false
			}
		} else {
			if perCount[10] > 0 {
				// 出现20(20-10-5(优先),或20-5-5-5)，10的个数大于0，10的个数个数--，5的个数大于0，5的个数减一,5的个数为0，返回false
				perCount[10]--
				if perCount[5] > 0 {
					perCount[5]--
				} else {
					return false
				}
			} else {
				// 10的个数为0，5的个数大于等于3，5的个数-3，否则返回false
				if perCount[5] >= 3 {
					perCount[5] = perCount[5] - 3
				} else {
					return false
				}
			}
		}
	}
	return true
}
```