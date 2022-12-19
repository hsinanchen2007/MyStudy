### 解题思路
java和python。python的执行用时和内存消耗击败99%，java较慢。
判断所有字符串的第一个字母，如果相同判断下一个字母。

### 代码
```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        int index = 0;
        String prefix = "";
        if(strs.length == 0) return"";
        label:
        while (index < strs[0].length()) {
            prefix = strs[0].substring(index, index + 1);
            for (String s2 : strs) {
                //if (index >= s2.length()) break label;
                if (index < s2.length() && prefix.equals(s2.substring(index, index + 1))) ;
                else break label;
            }
            index++;
        }
        return strs[0].substring(0, index);
    }
}
```
```python []
def longestCommonPrefix(self,strs: List[str]) -> str:
    if len(strs) == 0 :
        return ""
    for i in range(len(strs[0])):
        prefix = (strs[0])[i]
        for s in strs:
            if i >= len(s) or prefix != s[i]:
                 return (strs[0])[0:i] 
    return (strs[0])[0:i+1]
```

