### 解题思路
此处撰写解题思路
刚开始想的是右移2位最后为1   但是会有5>>2=1
通过右移动2位判断是否和n相等

### 代码

```golang
func isPowerOfFour(n int) bool {
	return isPowerOfFour1(n,1)
}
func isPowerOfFour1(n ,m int) bool  {
	if m<n{
		m=m<<2
		return isPowerOfFour1(n,m)
	}else if m==n{
		return true
	}else{
		return false
	}
}
```