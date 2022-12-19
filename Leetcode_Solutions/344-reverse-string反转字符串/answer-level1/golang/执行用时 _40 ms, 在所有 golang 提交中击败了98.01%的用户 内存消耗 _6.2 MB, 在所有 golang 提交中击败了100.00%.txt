### 解题思路
此处撰写解题思路
注意定义好区间，首位交换即可
### 代码

```golang
func reverseString(s []byte)  {
    n := len(s) //[l,n)
	mid := n / 2
	for i := 0; i < mid; i++ {
		s[i], s[n-i-1] = s[n-i-1], s[i]
	}
}
```