### 解题思路
以第一个字符串为参照，依次在后面的字符串中一个一个查找，遇到不一样的、长度不够的则跳出返回

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        String common = "";
        if(strs == null || strs.length == 0 || "".equals(strs[0])) return "";
        if(strs.length == 1) return strs[0];
        int index = 0;
        char current = strs[0].charAt(index);
        while(true){
            boolean isMatch = true;
            for(int i=1; i<strs.length; i++){
                if(index < strs[i].length()){
                    if(strs[i].charAt(index) != current){
                        isMatch = false;
                    }
                }else{
                    isMatch = false;
                }
            }
            if(isMatch) {
                common += current +"";
                index++;
                if(index < strs[0].length()){
                    current = strs[0].charAt(index);
                }else{
                    break;
                }
            }else{
                break;
            }
        }
        return common;
    }
}
```