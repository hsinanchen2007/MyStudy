解题思路 将字符转换成数组，然后用切片切割之后再拼接```
代码块
func reverseLeftWords1(s string, n int) string {
	str := strings.Split(s, "")
	strs1 := str[:n]

	strs2 := str[n:]
	str1 := strings.Join(strs1,"")
	str2 := strings.Join(strs2,"")
	fmt.Println(str2+str1)
	return  str2+str1
}
