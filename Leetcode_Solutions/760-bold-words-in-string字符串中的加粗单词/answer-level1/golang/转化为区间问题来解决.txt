### 解题思路
1. 找出所有配当前单词的所有位置，每一个位置记录为一个区间；
2. 合并相交的区间；
3. 根据区间添加标识到字符串。

### 代码

```golang
func boldWords(words []string, S string) string {
    l := len(words)

    //标出tag起止位
    mask := [][]int{}
    for i := 0; i < l;i++ {
        idx := strings.Index(S,words[i])
        base := 0  
        //找出所有配当前单词的位置      
        for idx != -1 {
            //+1 cc匹配ccc 有两个位置
            end := idx + 1 + base
            mask = append(mask,[]int{idx + base,idx + len(words[i]) + base})
            idx = strings.Index(S[end:],words[i])
            base = end
        }        
    }

    if len(mask) == 0 {
        return S
    }

    //merge tag的起止位
    sort.Slice(mask, func(i, j int) bool { 
        if mask[i][0] == mask[j][0] {
            return mask[i][1] < mask[j][1]
        }
        return mask[i][0] < mask[j][0]
    })
    mergeMask := [][]int{mask[0]}
    for i := 1; i < len(mask); i++ {
        tmp := mergeMask[len(mergeMask)-1]
        //[0,1][1,2] => [0,2]
        if tmp[1] >= mask[i][0] {
            if tmp[1] < mask[i][1] {
                tmp[1] = mask[i][1]
            }
        } else {
            mergeMask = append(mergeMask,mask[i])
        }
    }

    //起止位置加入标识
    var prev []int    
    buff := bytes.Buffer{}
    for i := 0; i < len(mergeMask); i++ {
        v := mergeMask[i]
        if prev == nil {
            buff.WriteString(S[:v[0]])
        } else {
            buff.WriteString(S[prev[1]:v[0]])
        }
        
        buff.WriteString("<b>")
        buff.WriteString(S[v[0]:v[1]])
        buff.WriteString("</b>")
        prev = v
    }

    buff.WriteString(S[prev[1]:])
    
    return buff.String()
}
```