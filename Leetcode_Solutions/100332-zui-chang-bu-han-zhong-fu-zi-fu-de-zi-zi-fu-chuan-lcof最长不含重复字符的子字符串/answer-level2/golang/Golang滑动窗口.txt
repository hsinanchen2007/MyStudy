### 代码

```golang
func lengthOfLongestSubstring(s string) int {
    if len(s)==0{
        return 0
    }
    note:=map[byte]int{}
    for i:=0;i<len(s);i++{
        note[s[i]]=-1
    }
    head,tail,max,length:=0,0,0,0
    for ;tail<len(s);tail++{
        index:=note[s[tail]]
        if index==-1{   // 窗口中没有这个字符,将其加入窗口
            note[s[tail]]=tail
            length++
            if length>max{
                max=length
            }
        }else{          // 如果有这个字符，将head指到下一个
            for ;head<index;head++{
                note[s[head]]=-1
            }
            head++
            note[s[tail]]=tail
            length=tail-head+1
        }
    }
    return max
}
```