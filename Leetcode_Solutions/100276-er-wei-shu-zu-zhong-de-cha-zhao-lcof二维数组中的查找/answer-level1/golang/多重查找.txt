#### 解题思路:
>  多重遍历获取值是否存在
``` go
	for _, v := range matrix {
		for _, value := range v {
			if value == target {
				return true
			}
		}
	}
	return false
```