两种方法，方法一是参照他人讲解KMP时给的示例解的，代码比较好理解；方法二是我自己写的，代码可能看上去不太好看
方法一
![image.png](https://pic.leetcode-cn.com/cdd1abe2628f86250a15b45336b45124e5a212ea6b6ef75ef3e001ac05ae9d3f-image.png)
```
func strStr(haystack string, needle string) int {
    var lenH int = len(haystack)
	var lenN int = len(needle)
    var i, j int
	if lenN > lenH{
		return -1
	}
	if lenN == 0 && lenH== 0 {
		return 0
	}
	
	for i < lenH && j < lenN {
		if haystack[i] == needle[j] {
			i++
			j++
		} else {
			i = i - j + 1
			j = 0
		}
	}
	if j == lenN {
		return i - j
	}

	return -1
}
```

方法二
![image.png](https://pic.leetcode-cn.com/442777b455230f3f3d4aaf10d8ac70443d3bc1ce3d7f6cfc472c6e414ce6202a-image.png)
```
func strStr(haystack string, needle string) int {
	if len(needle) > len(haystack) {
		return -1
	}
	if len(needle) == 0 || len(haystack) == 0 {
		return 0
	}
	//var index int = 0
	for i := 0; i < len(haystack); i++ {
		tmp := i
		for j := 0; j < len(needle); j++ {
			if needle[j] == haystack[tmp] && (len(haystack)-tmp >= len(needle)-j) {
				tmp++
			} else {
				break
			}
		}
		if tmp-i == len(needle) {
			return i
		}
	}

	return -1
}
```


