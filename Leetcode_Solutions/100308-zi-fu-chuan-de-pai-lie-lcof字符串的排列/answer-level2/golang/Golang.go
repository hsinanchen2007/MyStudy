### 解题思路
![image.png](https://pic.leetcode-cn.com/e2332378a4a286b5630fdc3bf17a46f7688a6754ca36eba6526ccaa108a18a2f-image.png)


### 代码

```golang
func permutation(s string) []string {
	if len(s) == 0 {
		return []string{}
	}
	dict := map[string]bool{}
	str := []byte(s)
	var f func(index int)
	f = func(index int) {
		if index == len(str) {
			dict[string(str)] = true
			return
		}
		for i := index; i < len(str); i++ {
			tmp := str[index]
			str[index] = str[i]
			str[i] = tmp
			f(index + 1)
			str[i] = str[index]
			str[index] = tmp
		}
	}
	f(0)
	res := []string{}
	for k, _ := range dict {
		res = append(res, k)
	}
	return res
}
```