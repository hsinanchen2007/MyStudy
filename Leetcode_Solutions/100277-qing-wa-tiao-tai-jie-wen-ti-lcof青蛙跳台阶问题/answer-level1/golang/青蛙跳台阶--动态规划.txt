### 解题思路
此处撰写解题思路
	台阶数和步数的关系
	f(n) = f(n-1) + f(n-2)
	f(1) = 1  f(2) = 2
### 代码

```golang
func numWays(n int) int {
    if n ==0 {
        return 1
    }

    if n==1 || n==2{
		return n
	}

	s := make([]int,n+1)
	s[1] = 1
	s[2] = 2
	for i:=3;i<=n;i++ {
		s[i] = (s[i-1] + s[i-2]) % 1000000007
	}

	return s[n]
}
```