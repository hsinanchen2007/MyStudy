### 解题思路
使用字典记录计算过的值 下次就不用重复计算了
### 代码

```golang
func fib(N int) int {
	recoder := make(map[int]int)
    return fibHelper(N, recoder)
}

func fibHelper(N int, recorder map[int]int) int {
	if N == 0 {
		return 0
	} else if N == 1 {
		return 1
	} else if _, ok := recorder[N]; ok {
		return recorder[N]
	} else {
		res := fibHelper(N - 1, recorder) + fibHelper(N - 2, recorder)
		recorder[N] = res
	    return res
	}
}
```