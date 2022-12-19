### 解题思路
此处撰写解题思路

### 代码

```golang
func largeGroupPositions(S string) [][]int {
	res:=make([][]int,0)
	str:=[]rune(S)
	index:=0
	count:=0
    //记录有没有梁旭相同的
	flag:=false
	for i:=0;i< len(str)-1;i++{
		if str[i+1]==str[i]{
			count++
			flag=true
		}else{
            //如果出现过连续相同，那么最后一个相同的 char 也应该算进去
			if flag{
				count++
			}
			if count>=3{
				res= append(res, []int{index,index+count-1})
			}
			count=0
			index=i+1
			flag=false
		}
	}
	if len(str)>=2&&str[len(str)-1]==str[len(str)-2]{
		count++
		if count>=3{
			res= append(res, []int{index,index+count-1})
		}
	}
	return res
}
```