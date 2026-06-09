### 解题思路
双指针+哈希查找
### 代码

```golang
func lengthOfLongestSubstring(s string) int {
    a:=make(map[byte]int)
    length:=len(s)
    var i,j,res int
    
    for ;j<length;j++{
        if _,ok:=a[s[j]];!ok{
            a[s[j]]=j
            if res<len(a){
                res=len(a)
            }
        }else{
            for ;i<j;i++{
                if s[i]!=s[j]{
                    delete(a,s[i])
                }else{
                    a[s[i]]=j
                    i++
                    break
                }
            }
        }
    }
    return res
}

//------------------------------------------------------------------------------------------------
func lengthOfLongestSubstring(s string) int {
    a:=make(map[byte]int)
    length:=len(s)
    var i,j,res int
    
    for ;j<length;j++{
        if v,ok:=a[s[j]];ok&&v>=i{
           i=v+1
        }
        a[s[j]]=j
        if res<j-i+1{
            res=j-i+1
        }
    }
    return res
}
```