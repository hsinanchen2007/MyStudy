### 解题思路
map记录字符串出现以及出现次数，sort对长度进行排序。
根据题意，只需要把符合要求的子串找出来并排除掉就好。

具体看代码：

### 代码

```golang
func minimumLengthEncoding(words []string) int {
    //记录初始的字符串个数
    count := len(words)

    //记录每个字符串出现的次数
    m := make(map[string]int)
    //记录不同长度字符串的位置
    //二维数组的，目的是相同长度的字符串可能右多个
    sort := make([][]int,8)

    //记录字符串的开始位置
    start := 7

    for k,v := range words {
        sort[len(v)] = append(sort[len(v)],k)
        if start > len(v) {
            start = len(v)
        }
        m[v]++
    }

    // fmt.Println(m,sort,start)

    //处理过程
    for i:=start;i<len(sort);i++ {
        //从长度最小的子串开始执行
        //这样做的目的是处理如:["me","me","time"]的情况
        for _,v := range sort[i] {
            //得到需要处理的字符串s
            s := words[v]
            for j:=0;j<len(s);j++ {
                // fmt.Println(s,s[j:],m[s[j:]])
                //j从0开始，这样就不会漏掉对与s的其他字符串的处理
                if s[j:] == s && m[s[j:]] > 1   {
                    //当存在其他与s相同的字符串时
                    //m[s]肯定大于1，那么再最后建立索引字符串时，重复的肯定只计算一个，就将count-1，且m[s]-1
                    count--
                    m[s[j:]]--
                } else if s[j:] != s && m[s[j:]] > 0 {
                    //不是重复的情况
                    count--
                    delete(m,s[j:])
                }
            }
        }
    }
    // fmt.Println(m,sort,start,count)
    res := 0

    for k,v :=range m {
        if v > 0{
            res += len(k)
        }
    }

    return res+count
}
```