### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
    int index = 0;
    if(strs.length == 0)
        return "";
    String pre = strs[0];
    for(int i = 1; i < strs.length; i++){
        index = strs[i].indexOf(pre);
        while(index != 0){
            pre = pre.substring(0, pre.length()-1);
            index = strs[i].indexOf(pre);
        }
    }
    return pre;
}
}
```