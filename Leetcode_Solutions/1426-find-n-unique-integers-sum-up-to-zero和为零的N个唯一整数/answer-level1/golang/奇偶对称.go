### Mojotech
此处撰写解题思路
[Go技术博客mojotech](https://mojotv.cn)
### 代码

```golang
func sumZero(n int) []int {
	if n == 0 {
		return []int{0}
	}
	if n %2 == 0 {
		return makeEvenArray(n/2)
	}else {
        res := makeEvenArray((n-1)/2)
		return append(res,0)
	}
}

func makeEvenArray(n int)(res []int){
    res = []int{}
	for i:=1;i<=n;i++{
        res = append(res,i,-i)
	}
	return
}
```