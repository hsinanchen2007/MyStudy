### 解题思路
太简单，看代码吧

### 代码

```golang
func toLowerCase(str string) string {
	var ret []byte
	for i := 0; i < len(str); i++ {
		if str[i] >=65 && str[i] <= 90 {
			ret = append(ret, str[i] + 32)
		} else {
			ret = append(ret, str[i])
		}
		
	}
	return string(ret)
}
```