### 解题思路
1）漂亮数组每个元素乘倍仍然是漂亮数组
2）漂亮数组每个元素加减仍然是漂亮数组
3）基数漂亮数组append偶数漂亮数组仍然是漂亮数组
4）漂亮数组内部删除部分元素仍然是漂亮数组
基于最小漂亮数组进行成倍扩容，然后删除超过N的元素即可

### 代码

```golang
func beautifulArray(N int) []int {

	sumv := []int{1,2}
	i := 2
	for i < N {
		a1 := make([]int, len(sumv))
		a2 := make([]int, len(sumv))
		for k, v := range sumv {
			a1[k] = v*2-1
			a2[k] = v*2
		}
		sumv = append(a1, a2...)
		i = i*2
	}
	retslice := make([]int,0, N)
	for _, v := range sumv {
		if v <= N {
			retslice = append(retslice, v)
		}
	}
	return retslice
}
```