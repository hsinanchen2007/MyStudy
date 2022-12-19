### 解题思路
如果用库函数，本题其实很简单。先把字符串按空格拆分，然后逆序输出每个词即可（手动在每个词中间加个空格）  

不用库函数，我的解法分三步：  
1. 将源字符串求逆，得到字符反过来的顺序，这样每个词也变成了逆序。
2. 使用双指针，跳过慢指针的空格，将每个词进行求逆。这样就把每个单词的顺序调转了回来。
3. 单词拼接，中间加空格  


### 代码

```golang
func reverseWords(s string) string {
	n := len(s)
	r := []byte(s)
	reverse(r)
	var out []byte
	for fast,slow := 0,0; fast < n; fast++ {
		if slow < n && r[slow] == ' ' {
			slow++
		} else if fast == n-1 || r[fast+1] == ' ' {
			if len(out) != 0 {
				out = append(out, ' ')
			}
			out = append(out, reverse(r[slow:fast+1])...) // 拼接两个[]byte可以用append的可变参数特性来实现
			slow = fast + 1
		}
	}
	return string(out)
}

func reverse(b []byte) []byte { // reverse函数有两个功能，调转b，并能返回b
	for start, end := 0, len(b)-1; start < end; start, end = start+1, end-1 {
		b[start], b[end] = b[end], b[start]
	}
	return b
}
```