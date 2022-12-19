![image.png](https://pic.leetcode-cn.com/56f23d2d0df00707eb1cdda8a9c8d9c9f8378111243ccee00ffe593e744d5393-image.png)
```
func buddyStrings(A string, B string) bool {
	aLen,bLen := len(A),len(B)
	if aLen != bLen {
		return  false
	}
	if strings.EqualFold(A,B){
		counts := make(map[byte]int)
		for i:= 0;i< len(A);i++{
			counts[byte(A[i] -'a')]++
		}
		for _,v := range counts{
			if v > 1{
				return  true
			}
		}
		return  false
	}
	first,second := -1,-1
	for i:= 0;i < len(A);i++{
		if A[i] != B[i]{
			switch {
			case first == -1:
				first = i
			case second == -1:
				second = i
			default:
				return  false
			}
		}
	}
	return  second != -1 && A[first] ==  B[second] && A[second] == B[first]
}
```
