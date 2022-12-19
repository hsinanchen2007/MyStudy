```
func climbStairs(n int) int {
    var hs map[int]int
	hs=make(map[int]int)
	var fnc func(n int,hs map[int]int) int
	fnc= func(n int,hs map[int]int) int {
		if n<=2{
			return n
		}
		if v,ok:=hs[n];ok{
			return v
		}
		rsq:= fnc(n-1,hs)+fnc(n-2,hs)
		hs[n]=rsq
		return rsq
	}
	return fnc(n,hs)
}
```
