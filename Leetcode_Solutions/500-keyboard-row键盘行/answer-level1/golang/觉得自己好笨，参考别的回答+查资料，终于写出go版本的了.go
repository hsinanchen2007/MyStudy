
func findWords(words []string) []string {
```
 	dic1 := "asdfghjklASDFGHJKL"//大小写都放进去就不用在后面再区分了
	dic2 := "qwertyuiopQWERTYUIOP"
	dic3 := "zxcvbnmZXCVBNM"
	var result []string //这个是用来接遍历后符合匹配的元素
	for i:=0; i<len(words); i++  {//第一层循环遍历words
		n1, n2, n3 := 0, 0, 0   
		for j:=0; j<len(words[i]); j++  {//第二遍遍历words的每一个元素
			if  strings.Contains(dic1, string(words[i][j])) == true{
				        n1++  //每找到一次符合的元素，就在这个键盘行+1
                
			}
			if  strings.Contains(dic2, string(words[i][j])) == true{
                        n2++
					
			}
			if  strings.Contains(dic3, string(words[i][j])) == true{
				        n3++    
                    
			}
		}
        //判断是否每次得到的元素次数和words其中每一个的元素长度符合，如果符合说明完全匹配
        if n1 == len(words[i]) || n2 == len(words[i]) || n3 == len(words[i]){
            result = append(result, string(words[i]))
        }
	}
	return result
```
｝