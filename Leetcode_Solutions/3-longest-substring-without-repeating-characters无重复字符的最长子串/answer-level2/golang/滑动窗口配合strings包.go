### 解题思路
滑动窗口解题，配合 strings 包。  
加上strings包中的for循环，总的时间复杂度为 $O(n^2)$

### 代码

```golang
func lengthOfLongestSubstring(s string) int {
    var max int
    i, j := 0, 1
    for ; j < len(s);{
        if !strings.Contains(s[i:j], string(s[j])){
            j+=1
        }else{
            if j-i>max{
                max = j-i
            }
            i+=strings.Index(s[i:j], string(s[j]))+1
            j+=1
        }
    }

    if len(s)!=0&&!strings.Contains(s[i:j-1], string(s[j-1]))&&j-i>max{
        max = j-i
    }
    return max
}
```