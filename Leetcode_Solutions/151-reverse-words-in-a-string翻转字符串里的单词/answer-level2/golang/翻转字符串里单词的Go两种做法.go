```go
package main

import (
	"regexp"
	"strings"
	"unsafe"
)

// https://leetcode-cn.com/problems/reverse-words-in-a-string/submissions/
func main() {

	resule := reverseWords_1("the sky is blue")
	if resule != "blue is sky the" {
		panic("error")
	}

	resule = reverseWords_2("the sky is blue")
	if resule != "blue is sky the" {
		panic("error")
	}
}

/*
执行用时：0 ms
内存消耗：4.1 MB
*/
func reverseWords_1(s string) string {
	s = strings.TrimSpace(s)
	ss := regexp.MustCompile(" +").Split(s, -1)
	for i := 0; i < len(ss)/2; i++ {
		if ss[i] == ss[len(ss)-1-i] {
			continue
		}
		s = ss[i]
		ss[i] = ss[len(ss)-1-i]
		ss[len(ss)-1-i] = s
	}
	return strings.Join(ss, " ")
}

/*
执行用时：0 ms
内存消耗：3.3 MB
*/
func reverseWords_2(s string) string {
	if len(s) == 0 {
		return s
	}
	s_arr := str2bytes(s)
	var (
		t    byte
		i, j int
	)
	size := len(s_arr)
	mid := size / 2
	left := 0
	word := true
	for i = 0; i < mid; i++ {
		t = s_arr[i]
		if s_arr[size-1-i] != ' ' || !word && s_arr[size-1-i] == ' ' {
			s_arr[left] = s_arr[size-1-i]
			if s_arr[size-1-i] == ' ' {
				word = true
			} else {
				word = false
			}
			left++
		}
		s_arr[size-1-i] = t
	}

	for i = mid; i < size; i++ {
		if word {
			if s_arr[i] != ' ' {
				s_arr[left] = s_arr[i]
				word = false
				left++
			}
		} else {
			if s_arr[i] != ' ' {
				s_arr[left] = s_arr[i]
			}
			if s_arr[i] == ' ' {
				s_arr[left] = s_arr[i]
				word = true
			}
			left++
		}
		if left-1 != i && s_arr[i] != ' ' {
			s_arr[i] = ' '
		}
	}

	start := 0
	end := 0
	for i = 0; i < size; i++ {
		if s_arr[i] == ' ' || i == size-1 {
			if s_arr[i] != ' ' && i == size-1 {
				end = i
			} else {
				end = i - 1
			}
			if start > end {
				end -= 1
				break
			}
			mid = (end + start) / 2
			for j = start; j <= mid; j++ {
				t = s_arr[j]
				s_arr[j] = s_arr[end-j+start]
				s_arr[end-j+start] = t
			}
			if i != size-1 {
				start = i + 1
				end = start
			}
		}
	}
	if end < -1 {
		end = -1
	}
	return bytes2str(s_arr[:end+1])
}

func str2bytes(s string) []byte {
	x := (*[2]uintptr)(unsafe.Pointer(&s))
	h := [3]uintptr{x[0], x[1], x[1]}
	return *(*[]byte)(unsafe.Pointer(&h))
}

func bytes2str(b []byte) string {
	x := (*[3]uintptr)(unsafe.Pointer(&b))
	h := [2]uintptr{x[0], x[1]}
	return *(*string)(unsafe.Pointer(&h))
}

```
