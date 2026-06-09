```
func countAndSay(n int) string {
	var res string = "1#"
	for i := 1; i < n; i++ {
		tmp := ""
		num_len := 1
		for j := 0; j < len(res); j++ {
			if j+1 < len(res) && res[j] != res[j+1] {
				tmp += fmt.Sprint(num_len) + string(res[j])
				num_len = 1
			} else {
				num_len += 1
			}
		}
		res = tmp + "#"
	}
	return res[:len(res)-1]
}
```
