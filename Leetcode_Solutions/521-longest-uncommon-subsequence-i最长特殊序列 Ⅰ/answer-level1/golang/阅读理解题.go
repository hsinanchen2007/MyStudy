### 解题思路
此处撰写解题思路

### 代码

```golang
func findLUSlength(a string, b string) int {
    //a,b两个字符串长度相同时，如果a!=b，那么a或者b都可以是特殊子序列
    //a,b两个字符串长度不相同时，长度大的那个字符串是 最大特殊子序列
    if len(a)==len(b){
        if a==b{
            return -1
        }else{
            return len(a)
        }
    }else{
        if len(a)>len(b){
            return len(a)
        }
        return len(b)
    }
    return -1
}
```