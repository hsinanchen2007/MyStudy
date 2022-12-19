### 解题思路
此处撰写解题思路

### 代码

```golang
func numberOfLines(widths []int, S string) []int {
	index:=0
	count:=0
	for i:=0;i< len(S);i++{
		if index+widths[S[i]-'a']>100{
			index=widths[S[i]-'a']
			count++
		}else{
			index+=widths[S[i]-'a']
		}
	}
    if index>0{
        count++
    }
	return []int{count,index}
}
```