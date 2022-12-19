基于golang的实现

可以根据官方给的实例为例，比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时
```
L   C   I   R
E T O E S I I G
E   D   H   N
```

每满 行数-1 可以为一组，
如上图，LE ET CO ...等等为一组，
当组数为偶数时正序赋值，当组数为奇数时倒序赋值即可。

下面是实现方法，耗时12ms,占用内存5.3M
```
func convert(s string, numRows int) string {
    	if numRows == 1 {
		return s
	}
	b := numRows - 1
	strArr := make([]string, numRows)
	for k, v := range s {
		if (k/b)%2 == 0 {
			strArr[k%b] += string(v)
		} else {
			strArr[b-(k%b)] += string(v)
		}
	}
	return strings.Join(strArr,"")
}
```
