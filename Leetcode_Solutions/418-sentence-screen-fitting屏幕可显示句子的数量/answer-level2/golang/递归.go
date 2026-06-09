
解题思路：
1：将sentence处理成字符串p
2：将p放入屏幕矩阵中，通过getEndPoint函数，根据字符串在矩阵的起始位置，获取该字符串在矩阵中的最后一个字符的坐标位置。
3：getEndPoint中，判断当前行是否能装下该字符串，如果装不下，把剩下的字符串截断，再递归通过getEndPoint递归计算最后一个字符的坐标位置
```

func wordsTyping(sentence []string, rows int, cols int) int {
	p := strings.Join(sentence," ")
	var rowStart,colStart,res int
    for ;;{
    	rowEnd,colEnd := getEndPoint(p,rowStart,colStart,rows,cols)
    	if rowEnd >= rows {
    		break
		}
		res++
		rowStart,colStart = rowEnd,colEnd+2
		if colStart >= cols {
			rowStart,colStart = rowStart+1,0
			// 优化时间开始
			res = res*(rows/rowStart)
			rowStart = rows - rows%rowStart
			// 优化时间结束
		}
	}
    return res
}

func getEndPoint(p string,rowStart,colStart,rows,cols int)(rowEnd,colEnd int) {
	// 超行
	if rowStart >= rows {
		return rowStart,colStart
	}
	// 1行够用
	if colStart + len(p) <= cols {
		return rowStart,colStart+len(p)-1
	}
    // 1行不够用
    var pNew string = p[cols-colStart+1:]
    if p[cols-colStart] != ' '{
		pBefores := strings.Split(p[0:cols-colStart+1]," ")
		pNew = fmt.Sprintf("%s%s",pBefores[len(pBefores)-1],pNew)
	}
	return getEndPoint(pNew,rowStart+1,0,rows,cols)
}
```
