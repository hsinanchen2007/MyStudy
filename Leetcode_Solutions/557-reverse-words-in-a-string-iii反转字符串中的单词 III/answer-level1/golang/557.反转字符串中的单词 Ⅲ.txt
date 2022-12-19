### 解题思路

方法比较慢，但很直观容易想到。

### 代码

```golang
func reverseWords(s string) string {
	tmp := strings.Split(s," ")			//按空格把每个单词分开
	res := ""
	for i := 0;i < len(tmp);i++ {		//把每个单词反转，添加进res字符串
		tmp[i] = reverse(tmp[i])
		res += tmp[i] + " "
	}
	return res[:len(res) - 1]			//返回时记得把最后多加的空格去掉

}
func reverse(s string) string {
	tmp := ""
	for i := len(s) - 1;i >= 0;i-- {
		tmp = tmp + string(s[i])
	}
	return tmp
}
```