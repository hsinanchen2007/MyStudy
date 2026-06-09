func climbStairs(n int) int {
    if n<=1{
        return n
    }
    a,b:=1,1
	for i:=3;i<=n;i++{
		c:=a+b
		a=b
		b=c
	}
	return a+b
    /*递归超时
    if n<=2{
		return n
	}else{
		return climbStairs(n-1)+climbStairs(n-2)
	}*/
}