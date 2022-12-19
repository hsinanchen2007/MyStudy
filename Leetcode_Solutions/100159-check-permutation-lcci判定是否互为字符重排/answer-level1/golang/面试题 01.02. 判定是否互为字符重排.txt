### 解题思路
一个字符串长度

### 代码

```golang
func CheckPermutation(s1 string, s2 string) bool {
	if len(s1) != len(s2) {
		return false
	}
	arr := make([]int,  27)
	arr2 := make([]int,  27)

	for i := 0; i < len(s1); i++ {
		data1 := s1[i] - 'a'
		arr[int(data1)] = 1
		data2 := s2[i] - 'a'
		arr2[int(data2)] = 1
	}

	for i:=0;i<27;i++{
		if arr[i] != arr2[i]{
			return false
		}
	}
	return true

}
```