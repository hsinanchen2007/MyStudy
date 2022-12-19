### 解题思路
![666.png](https://pic.leetcode-cn.com/2b6c44164d596b5b61685f1f02fc0ce98851d8dcfa8e0b6f99d33bbd40dfc540-666.png)

有用的话点个赞 让我知道


### 代码

```golang
func advantageCount(a []int, b []int) (ans []int) {
	yuanlai := arr1_copy(b)
	sort.Ints(a)
    ans=make([]int,len(b))
    	for i := 0; i < len(b); i++ {
		b[i] = i
	}
	sort.Slice(b, func(i, j int) bool {
		return yuanlai[b[i]] < yuanlai[b[j]]
	})
    for  i:=0;i<len(b);i++{
        fmt.Print(yuanlai[b[i]]," ")
    }
	j := 0
	end := len(b) - 1
	for i := 0; i < len(a); i++ {
		if a[i] > yuanlai[b[j]] {
			ans[b[j]] = a[i]
			j++
		} else {
			ans[b[end]] = a[i]
			end--
		}
	}
	return ans
}

func arr1_copy(b []int) []int {
	a := make([]int, len(b))
	for i := 0; i < len(a); i++ {
		a[i] = b[i]
	}
	return a
}
```