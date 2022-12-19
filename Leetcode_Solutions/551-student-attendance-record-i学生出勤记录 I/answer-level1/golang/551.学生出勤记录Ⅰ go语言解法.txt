### 解题思路

十分简单的题，直接上代码。

### 代码

```golang
func checkRecord(s string) bool {
	num_a := 0   //统计A的个数
	num_l := 0   //统计连续L的个数
	for i := 0;i < len(s);i++ {
		if s[i] == 'A' {
			num_a++
			if num_a == 2 {
				return false       //A个数要是等于2，肯定false了，后面不用看了直接返回
			}
		}
		if s[i] == 'L' {
			num_l++
			if num_l == 3 {       //连续的L的个数等于3才会false，否则num_l重置为0
				return false
			}
		}else {
			num_l = 0
		}
	}
	return true
}
```