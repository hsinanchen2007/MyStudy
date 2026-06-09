### 解题思路
此处撰写解题思路

### 代码

```golang
func countAndSay(n int) string {
	if n == 1 {
		return "1"
	} else if n == 2 {
		return "11"
	} else {
		s := countAndSay(n - 1) //11
		numStr := ""
		count := 1
		for i := 1; i < len(s); i++ {
			if s[i] == s[i-1] {
				count += 1
			} else {
				o := strconv.Itoa(count)
				numStr = numStr+o+string(s[i-1])
				count = 1
			}
		}
		return numStr+strconv.Itoa(count)+string(s[len(s)-1])    //单独处理最后一个元素
	}
}
```