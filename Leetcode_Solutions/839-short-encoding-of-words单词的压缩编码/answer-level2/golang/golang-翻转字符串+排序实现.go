### 翻转字符串+排序实现
```
//翻转字符串实现
func minimumLengthEncoding(words []string) int {
    if words==nil || len(words)==0{
        return 0
    }
    //1、翻转字符串
    for i:=0;i<len(words);i++{
        words[i]=reverse(words[i])
    }
    //2、排序(升序排列)
    sort.Strings(words)
    //3、给字符串添加一个"*"，
    //为了实现后一个与前一个比较
    words=append(words,"*")
    res:=0//保存结果
    for i:=0;i<len(words)-1;i++{
        //如果后一个字符串的前缀是以前一个字符串为前缀构成的
        //那么前一个就不需要管了
        if strings.HasPrefix(words[i+1],words[i]){
            continue
        }
        //否则将其长度加入结果集中，并加上一个"#"的长度
        res+=len(words[i])+1
    }
    return res
}

//翻转字符串，执行字符串翻转要将其变为byte数组才能进行换位操作
func reverse(str string)string{
    bytes:=[]byte(str)
    l,r:=0,len(bytes)-1
    for l < r{
        bytes[l],bytes[r]=bytes[r],bytes[l]
        l++
        r--
    }
    return string(bytes)
}

```
### 个人认为，这个题使用字典树其实并不合适，不算最优解，实现起来也比较麻烦（容易忘）；看来，刷题还是要找准题目的内涵，死套模板反而效果不佳
