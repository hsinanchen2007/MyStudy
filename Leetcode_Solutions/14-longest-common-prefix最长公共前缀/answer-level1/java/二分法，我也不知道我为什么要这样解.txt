### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0){
            return "";
        }
        int minLength = strs[0].length();
        for (String str : strs) {
            minLength = Math.min(minLength,str.length());
        }
        return longestCommonPrefixHelpFun(strs,0,minLength);
    }

    private String longestCommonPrefixHelpFun(String[] strs, int start, int end) {
        String pre = strs[0].substring(start,end);
        for (int i = 1; i < strs.length; i++) {
            if(!pre.equals(strs[i].substring(start,end))){
                if(end-start == 1){
                    return "";
                }
                String longestCommonPrefix = longestCommonPrefixHelpFun(strs, start, start + (end - start) / 2);
                if(longestCommonPrefix.length() == start + (end - start) / 2 - start){
                    return longestCommonPrefix + longestCommonPrefixHelpFun(strs,start + (end-start)/2, end);
                }
                return longestCommonPrefix;
            }
        }
        return pre;
    }
}
```