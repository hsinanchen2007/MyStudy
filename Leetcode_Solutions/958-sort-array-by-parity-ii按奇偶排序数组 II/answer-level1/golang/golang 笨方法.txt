```
func sortArrayByParityII(A []int) []int {
    var a []int // 奇数
	var b []int // 偶数

	for _,v := range A {
		if v % 2 == 0 {
			b = append(b,v)
		}else if v != 0{
			a = append(a,v)
		}
	}

	for k,_ := range A {
		switch  {
		case k == 0:
			A[k] = b[0]
			b = append(b[1:])
		case k % 2 == 0:
			A[k] = b[0]
			b = append(b[1:])
		case k % 2 != 0:
			A[k] = a[0]
			a = append(a[1:])
		}
	}
    return A
}
```