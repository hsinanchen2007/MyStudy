![1564906747(1).png](https://pic.leetcode-cn.com/e5721a6c1681f3b5260ef0c149b0ff37f238b8f168bad11e6b723c7eebcf2a26-1564906747\(1\).png)

``` golang []
func generateYangHui() func() []int {
	row := []int{1}
	return func () []int {
		lenght := len(row)
		newrow := []int{1}
		for len(newrow) != lenght {
			for i := 0;i < len(row)-1; i++ {
				newrow = append(newrow,row[i]+row[i+1])
			}
		}
		newrow = append(newrow,1)
		row = newrow
		return newrow
	}
}

func generate(numRows int) [][]int {
	if numRows == 0 {
		return nil
	}
	if numRows == 1 {
		return [][]int{{1}}
	}
	row := make([][]int,0)
	row = append(row, []int{1})
	a := generateYangHui()

	for i := 0;i < numRows-1 ;i ++ {
		row = append(row, a())
	}

	return row
}
```

用闭包的思想来解决，想一想，杨辉三角是不是和斐波那契数列很像呢，其实，它两是一样的。当前的值是要对上一次的值做处理，所以当然就想到闭包了