解题思路与过程：初始化一个int类型的变量x作为返回值。由于字符串底层是字节数组结构，使用是s[i]来遍历字符串s中的每一个字母。
对于每一个s[i]，若其是I，X，C中的任一个，则判断s[i+1]是否会和s[i]组合成题中的六种特殊情况，若是六种情况中的一种，则x加上s[i]+s[i+1]组合之后对应的值，并且执行i++用于跳过s[i+1]；若不是六种情况中的一种，则直接对x加上s[i]对应的字母所对应的值。若s[i]不是I，X，C中的一个，则x直接加上s[i]对应的值。
需要注意的是s[i+1]在i=len(s)时会发送数组越界情况，所以此处对s做了s=s+"I"的处理，在字符串s后面追加一个字符I用于避免数组越界问题，只要在遍历s(i)时不遍历最后一个字符I即可(通过设置for循环的上限为i<len(s)-1实现)
func romanToInt(s string) int {
	var x int
	s = s + "I"
	for i := 0; i < len(s)-1; i++ {
		switch string(s[i]) {
		case "M":
			x += 1000
		case "D":
			x += 500
		case "C":
			if string(s[i+1]) == "D" {
				x += 400
				i++
			} else if string(s[i+1]) == "M" {
				x += 900
				i++
			} else {
				x += 100
			}
		case "L":
			x += 50
		case "X":
			if string(s[i+1]) == "L" {
				x += 40
				i++
			} else if string(s[i+1]) == "C" {
				x += 90
				i++
			} else {
				x += 10
			}
		case "V":
			x += 5
		case "I":
			if string(s[i+1]) == "V" {
				x += 4
				i++
			} else if string(s[i+1]) == "X" {
				x += 9
				i++
			} else {
				x += 1
			}
		}
	}
	return x
}