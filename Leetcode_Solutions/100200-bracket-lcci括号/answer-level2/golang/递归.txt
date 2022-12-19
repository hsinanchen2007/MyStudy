**基本思想**

```
curL统计当前（个数，curR统计当前）个数
result作为结果集
```

**代码实现**

```
func helper(str string,result *[]string,curL int,curR int ,n int)  {
	if curL == curR && curL == n {
		*result = append(*result, str)
		return
	}else if curL == curR && curL < n{
		helper(str + "(",result,curL+1,curR,n)
	}else if curL < n && curR < curL{
		helper(str + "(",result,curL+1,curR,n)
		helper(str + ")",result,curL,curR+1,n)
	} else if curL == n && curR < n{
		helper(str + ")",result,curL,curR+1,n)
	}
}

func generateParenthesis(n int) []string {
	var result = make([]string,0)
	helper("",&result,0,0,n)
	return result
}
```
