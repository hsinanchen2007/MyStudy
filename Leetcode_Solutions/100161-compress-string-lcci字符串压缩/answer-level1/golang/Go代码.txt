![微信图片_20200316095857.png](https://pic.leetcode-cn.com/8c450bf3e939dc9258b270229a4066c304b081aab289a7d4174ec71a117071c1-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200316095857.png)

```golang
func compressString(S string) string {
    if len(S) < 3 {
        return S
    }
	buf := make([]byte, 0, len(S))
	num := 1
    buf = append(buf, S[0])
	for i := 1;i < len(S);i++ {
		if S[i-1] == S[i] {
			num++
		} else {
			buf = append(buf, []byte(strconv.Itoa(num))...)
			buf = append(buf, S[i])
			num = 1
		}
        if i == len(S) - 1 {
			buf = append(buf, []byte(strconv.Itoa(num))...)
        }
	}
	if len(buf) >= len(S) {
		return S
	}
	return string(buf)
}
```
