### 解题思路
此处撰写解题思路

### 代码

```golang
func myfunc(add, left int) []string {
	if left == 0 {
		return []string{""}
	}
	if add > left {
		return []string{""}
	}
	if add == left {
		tmp := ""
		for i := 0; i < left; i++ {
			tmp = tmp+")"
		}
		return []string{tmp}

	}
	//"("
	ret1 := myfunc(add+1, left-1)
	//")"

	ret := make([]string, 0)
	for _, v := range ret1 {
		ret = append(ret, "("+v)
	}
	if add != 0 {
		ret2 := myfunc(add-1, left-1)
		for _, v := range ret2 {
			ret = append(ret, ")"+v)
		}
	}

	return ret
}


func generateParenthesis(n int) []string {
	if n == 0 {
		return []string{""}
	}
	retslice := myfunc(1, 2*n-1)
	ret := make([]string, 0)
	for _, v := range retslice {
		ret = append(ret, "("+v)
	}
	return ret
}

```