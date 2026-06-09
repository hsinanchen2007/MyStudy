### 解题思路
用第一个字符串做参照, 逐位遍历, 遇到不够长或者不同则跳出. 取最后一位切片返回子字符串. 
注意输入的字符串数组是否含有元素, 没有直接返回空字符串
也可以最后判断下i是否大于0, 为0没必要切片, 直接返回空字符串即可

### 代码

```golang
func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 {
        return ""
    }
    i:=0
    for ;i<len(strs[0]);i++{
        same := true   
        for j:= 1; j<len(strs); j++{
            str := strs[j]
            if i >= len(str) {
                same = false
                break
            }
            if strs[0][i] != str[i] {
                same = false;
                break;
            }
        }
        if !same {
            break
        }
    }
    return string(strs[0][:i])
}
```