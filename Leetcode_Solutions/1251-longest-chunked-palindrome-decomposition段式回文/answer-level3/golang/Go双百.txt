这题从头和尾各往中间走，在限定了给出的字符串必是段式回文的情况下，可以放心大胆的匹配
ghiddghi
当头的ghi匹配到尾的ghi，那么res+2，再重新匹配dd即可

```golang
func longestDecomposition(text string) int {
	res:=0
	p1,p2:=0,0
	p3,p4:=len(text)-1,len(text)-1
	for p2<p3{
		if text[p1:p2+1]==text[p3:p4+1] {
			res+=2
			p1,p4=p2+1,p3-1
		}
		p2++
		p3--
	}
	if p1<=p4 {
		res++
	}
	return res
}
```