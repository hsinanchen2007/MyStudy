```
func longestCommonPrefix(strs []string) string {
    
    if len(strs) == 0 {  
        return ""
    }
    
    // 用来存放公共前缀
    commonPrefix := []byte{}
    // 当前索引
    index := 0
    loop := true
    
    for loop {
        
        var currPrefix byte 
        
        // 比对所有字符串同一索引位置的字符
        for k, v := range strs {
            
            if index > len(v) - 1 {  // 如果当前索引超过了任一字符串的长度，则退出循环
                loop = false
                break
            }
            
            if k == 0 {  // 第一个字符串的当前索引位置的字符，作为比对基准
                currPrefix = v[index]
            } else if (currPrefix != v[index]) {  // 第N个字符串的当前索引位置的字符和基准字符不同，则退出循环
                loop = false
                break
            } 
        }

        // 如果是正常遍历完所有字符串的当前索引，则加入到结果集中
        if loop { 
            commonPrefix = append(commonPrefix, currPrefix)
            // 索引自增
            index++ 
        }
    }
    
    return string(commonPrefix)
    
}
```
