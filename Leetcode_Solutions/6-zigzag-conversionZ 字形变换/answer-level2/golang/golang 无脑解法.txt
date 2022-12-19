golang 无脑解法

github: https://github.com/Crownt/leetcode


```
// 开辟二维空间，摆出要求形状再读取
// 时间复杂度：O(n)  空间复杂度：O(n)

func convert(s string, numRows int) string {

	if numRows==1 {
		return s
	}

	str := ""
	
	cols := len(s)/(2*numRows-2)*2  // cols为最终的列数
	temp := len(s)%(2*numRows-2)
	if temp>0 && temp<=numRows {
		cols += 1
	}else if temp>numRows {
		cols += 2
	}

	// 开辟二维空间，按要求将字符串摆出＇Z＇型
	grid := make([][]string, numRows)
	for i:=0; i<numRows; i++ {
		grid[i] = make([]string, cols)
	}

	index := 0
	for i:=0; i<cols; i++ {
		if i%2==0 {
			for j:=0; j<numRows; j++ {
				if index<len(s) {
					grid[j][i] = s[index:index+1]
					index++
				}			
			}
		}else {
			for j:= numRows-2; j>0; j-- {
				if index<len(s) {
					grid[j][i] = s[index:index+1]
					index++
				}	
			}
		}
	}

	// 从＇Z＇型排列中读取字符串
	for i:=0; i<numRows; i++ {
		for j:=0; j<cols; j++ {
			if grid[i][j] != "" {
				str += grid[i][j]
			}
		}
	}

	return str
}

```

