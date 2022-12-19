```
 func addBinary(a string, b string) string {
	i := len(a) - 1
	j := len(b) - 1
	res := ""
	flag := 0  //进位标识
	current := 0
    for  i >= 0 || j>= 0 {
		Inta,Intb := 0,0
		if (i >= 0){
			Inta = int (a[i] - '0')
		}
		if (j >= 0){
			Intb = int (b[j] - '0')
		}
		current = Inta + Intb + flag 
		flag = 0
		if current >= 2 {
			flag = 1
			current = current - 2 
		}
        cur := strconv.Itoa(current)
		res = cur + res
		i--
		j--
	}
	if flag == 1 {
		res = "1" + res
	}
	return res
}
```

这里要注意的是，访问是从字符串后面往前面走的，两个字符得用不同的数字来循环，因各是各的长度，要是用最长那个字符串-1来做最初始循环，就会演变变成低位补0，高位对齐的计算了。
