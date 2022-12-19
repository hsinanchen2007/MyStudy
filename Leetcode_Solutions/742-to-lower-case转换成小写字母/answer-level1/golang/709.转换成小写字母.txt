### 解题思路

没什么好说的...

### 代码

```golang
func toLowerCase(str string) string {
	var tmp []byte
	tmp = append(tmp,str...)
	for i := 0;i <len(tmp);i++ {
		if tmp[i] >=  65 && tmp[i] <= 90 {
			tmp[i] += 32
		}
	}
	return string(tmp)
}
```