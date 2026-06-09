### 解题思路
因为字符串是常量，所有先转换成byte类型
使用两个指针分别从头，尾找到元音位置，并交换位置。
### 代码

```golang
const A = byte('A')
const a = byte('a')
const E = byte('E')
const e = byte('e')
const I = byte('I')
const i = byte('i')
const O = byte('O')
const o = byte('o')
const U = byte('U')
const u = byte('u')

func yuan(s byte) bool {
	switch s {
	case A, a, E, e, I, i, O, o, U, u:
		return true
	}
	return false
}
func reverseVowels(s string) string {
	////a e i o u
	////hello
	////能否归并
	//// 转byte
	l := 0
	v := []byte(s)
	r := len(s) - 1 //[l...r]
	for true {
		for l < r {
			if yuan(v[l]) {
				break
			}
			l++
		}
		for l < r {
			if yuan(v[r]) {
				break
			}
			r--
		}
		if l >= r {
			break
		}
		v[l], v[r] = v[r], v[l]
		l++
		r--
	}
	return string(v)
}

```