思路：利用第7题. 整数反转的方法，直接求一个数翻转后的数。此外，如果x是负数，则肯定不是。另外reverse也考虑了超出int32的情况。

```
func isPalindrome(x int) bool {
    if x<0{
        return false
    }
    rX:=reverse(x)
    if x==rX{
        return true
    }else{
        return false
    }
}
func reverse(x int) int {
    //此题目是看的题解，不是自己想出来的，我对这种题目好像想不太明白
	ret:=0
	for x!=0{
		pop:=x%10
		x=x/10
		ret=ret*10+pop
		if ret <math.MinInt32||ret>math.MaxInt32{
			return 0
		}
	}
	return ret
}
```
