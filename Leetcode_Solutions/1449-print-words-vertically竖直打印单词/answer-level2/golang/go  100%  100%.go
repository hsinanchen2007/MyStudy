# go实现

##思路

```
1. 切分
2. 计算结果长度
3. 声明[]string，并填充
    填充规则：
            1. len(strs[j]) < resultLen && i >= len(strs[j])   //长度小于最大单词长度，并且当前除了范围
            2. result[i] = result[i] + string(strs[j][i])   //其他情况填充本身
4. 消除右边” “
```

##代码

```
func printVertically(s string) []string {
	var strs = strings.Split(s," ")
	var resultLen = 0
	for _,value := range strs{
		if resultLen < len(value){
			resultLen = len(value)
		}
	}

	var result = make([]string,resultLen)
	for i:=0;i<resultLen ;i++  {
		for j:=0;j<len(strs) ;j++  {
			if len(strs[j]) < resultLen && i >= len(strs[j]){
				result[i] = result[i] + " "
				fmt.Println(j)
			}else{
				result[i] = result[i] + string(strs[j][i])
			}
		}
		result[i] = strings.TrimRight(result[i]," ")
	}
	return result
}

```
