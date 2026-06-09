1.累除法
```
func isPowerOfTwo(n int) bool {

	for n!=1&&n!=0{
		if n%2==1{
			return false
		}
		n=n/2
	}
	if n==1{
		return true
	}
	return false
}
```

2.位运算
```
func isPowerOfTwo(n int) bool { // 神仙方法
	if n!=0 && n&(n-1) == 0 {
		return true
	}
	return false
}
```
