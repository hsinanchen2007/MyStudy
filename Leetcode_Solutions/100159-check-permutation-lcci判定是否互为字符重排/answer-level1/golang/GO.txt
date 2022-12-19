### 解题思路
此处撰写解题思路

### 代码

```golang
func CheckPermutation(s1 string, s2 string) bool {
    a1:=strings.Split(s1,"")
	a2:=strings.Split(s2,"")
	sort.Strings(a2)
	sort.Strings(a1)
	return reflect.DeepEqual(a1, a2)
}
```