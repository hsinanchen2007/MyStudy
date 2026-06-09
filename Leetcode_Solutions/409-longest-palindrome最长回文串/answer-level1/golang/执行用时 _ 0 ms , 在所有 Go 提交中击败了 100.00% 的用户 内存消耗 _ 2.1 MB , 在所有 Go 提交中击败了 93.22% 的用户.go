思路：这题其实只是用了个回文的概念，说人话，大概就是，我们给的字符串里有多少对，有多少对，就加多少对。去掉这些对以后还有没有落单的，有就加一个。
代码：
```
func longestPalindrome(s string) int {
	if len(s)<=1 {
		return len(s)
	}
	temp:=make([]int,52)
	for _,v:=range s{
		if v>=97 {
			temp[v-97]++
		}else{
			temp[v-39]++
		}
	}
	f,sum:=0,0
	for i:=0; i< len(temp); i++ {
		sum=sum+temp[i]
		if f==0 {
			if temp[i]%2!=0 {
				f=1
			}
		}else{
			if temp[i]%2!=0 {
				sum--
			}
		}
	}
	return sum
}
```
