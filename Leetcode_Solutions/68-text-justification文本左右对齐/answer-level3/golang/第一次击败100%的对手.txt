常规算法，时间复杂度o(n)，空间o(n)；

merge函数作用是合并在一行的单词；

fullJustify 函数是找到在一行的单词，调用merge合并，直到结束

```
func merge(words []string,start,end int,isEnd bool,maxWidth int)string{
    //start:单词开始的位置
    //end: 单词结束的位置
    //isEnd: 是否是最后一次，因为规定最后一次，单词间只有一个空格，末尾空格补齐
    //maxWidth: 每一行的宽度
    total := end-start
    totalLenChar := 0
    retByte := make([]byte,maxWidth)
    //fmt.Printf("start:%d end:%d isEnd:%v maxWidth:%d words:%v\n",start,end,isEnd,maxWidth,words[start:end])
    if total == 1{
        s := 0;
        for s<len(words[start]){
            retByte[s] = words[start][s]
            s++
        }
        for s<maxWidth{
            retByte[s] = ' '
            s++
        }
        return string(retByte)
    }
    for _,v := range(words[start:end]){
        totalLenChar += len(v)
    }
    if isEnd{
        s := 0
        for _,v := range(words[start:end]){
            for _,vv := range []byte(v){
                retByte[s] = vv
                s++
            }
            if(s<maxWidth){
                retByte[s] = ' '
                s++
            }
        }
        for s<maxWidth{
            retByte[s] = ' '
            s++
        }
        return string(retByte)
    }else{
        avg := (maxWidth-totalLenChar)/(total-1)
        mod := (maxWidth-totalLenChar)%(total-1)
        s := 0
        //fmt.Printf("avg:%d mode:%d total:%d s:%d byte:%V\n",avg,mod,total,s,retByte)
        for _,v := range(words[start:end]){
            for _,vv := range []byte(v){
                retByte[s] = vv
                s++
            }
            if s>=maxWidth{
                break
            }
            for i:=0;i<avg;i++{
                retByte[s] = ' '
                s++
            }
            if mod >0 {
                retByte[s] = ' '
                s++
                mod--
            }
        }
    }
    return string(retByte)
}
func fullJustify(words []string,maxWidth int)[]string{
    startIndex := 0
    endIndex := 1
    tmpCount := len(words[0])
    retSlice := []string{}

    for endIndex < len(words){
        if tmpCount + len(words[endIndex]) + (endIndex-startIndex)>maxWidth{
            retSlice =append(retSlice,merge(words,startIndex,endIndex,false,maxWidth))
            startIndex = endIndex
            tmpCount = 0
        }
        tmpCount += len(words[endIndex])
        endIndex++
    }
    retSlice =append(retSlice,merge(words,startIndex,endIndex,true,maxWidth))
    return retSlice
}
```