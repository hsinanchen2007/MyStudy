![image.png](https://pic.leetcode-cn.com/5dbc7b10d1081227d088764c7143b1fd2b1e7dceba297414f8adef8f298dc461-image.png)

```
func generate(numRows int) [][]int {
	if numRows == 0 {
		return [][]int{}
	}

	if numRows == 1 {
		return [][]int{{1}}
	}

	var ret = make([][]int, numRows)
	ret[0] = []int{1}
	for i := 1; i < numRows; i++ {
		var tmp = make([]int, i+1)
		for j := 0; j <= i; j++ {
			if j == 0 || j == i {
				tmp[j] = 1
				continue
			}
			tmp[j] = ret[i-1][j] + ret[i-1][j-1]
		}
		ret[i] = tmp
	}
	return ret
}
```

