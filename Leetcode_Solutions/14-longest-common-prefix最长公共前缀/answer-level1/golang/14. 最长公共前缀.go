### 解题思路
通过两次遍历，逐个比较

### 代码

```golang
func longestCommonPrefix(strs []string) string {
	itemsNum:=len(strs)
	//判断空切片
	if itemsNum==0{
		return ""
	}
	
	//最终结果。因为题目中指出字符的范围是a-z，可以使用[]byte来储存
	//byte其实就是uint8，而string[n]取值也是uint8
	result:=make([]byte,0,10)
	
	//获取最短字符串长度
	shortestLen:=getShortestLen(strs)
	
	//两个临时变量
	temp:=true //用来记录当前index的字符是否全都相同
	isBreak:=false //用来判断是否跳出外循环
	for i:=0;i<shortestLen&&!isBreak;i++{
		for j:=0;j<itemsNum-1;j++{
			if strs[j][i]!=strs[j+1][i]{
				temp=false
				isBreak=true
				break
			}
		}
		if temp{
			result=append(result,strs[0][i])
		}
	}
	return string(result)
}

func getShortestLen(strs []string)int{
	result:=math.MaxInt32
	for _,item:=range strs{
		if len(item)<result{
			result=len(item)
		}
	}
	return result
}
```