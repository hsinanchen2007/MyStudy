### 解题思路
此处撰写解题思路
思路其实很简单 首次遍历字符串数组O(n),获取到最小字符串k,然后按最短字符串的长度从0位开始遍历每个字符串 发现不一致则跳出O(kn) 则当前的下标执行最长前缀的最后一位  随便找个字符串截取就行 这里选择最小字符串 不要忘记的是 如果整个过程没有跳出 说明所以字符串都相等或最短字符串就是最小前缀 直接返回即可
### 代码

```golang
func longestCommonPrefix(strs []string) string {
    if len(strs) <= 0 {
        return ""
    } 
    temp := 0
    for i:=0; i< len(strs); i++ {
        if len(strs[i]) < len(strs[temp]) {
            temp = i
        }
    }
    flag := true
    num := 0
    for j:=0; j<len(strs[temp]); j++ {
        temptemp := strs[temp][j]
        for ii:=0; ii<len(strs); ii++ {
            if strs[ii][j] != temptemp {
                flag = false
                break
            }
        }
        if !flag {
            num = j
            break
        } 
    }
    //所有的字符串都相同
    if flag {
        return strs[temp]
    }else{
        return strs[temp][:num]
    }
   
}
```