### 解题思路
使用第一个字符串来匹配其他字符串，注意输入为{}和输入为一个字符串的情况，需要额外处理。
maxCom是最大公共长度，index是匹配字符串字符的下标值。
maxCom = Math.min(maxCom,index);是求所有公共字符串长度的最小值，这样才能匹配所有字符串。

### 代码

```java
class Solution {
    public static String longestCommonPrefix(String[] strs) {
        if (strs.length<1) return "";
        if (strs.length==1) return strs[0];
        String first = strs[0];
        int maxCom = Integer.MAX_VALUE;
        int index;
        for (int i = 1;i<strs.length;i++){
            index = 0;
            while (index < first.length() && index < strs[i].length()){
                if (first.charAt(index) == strs[i].charAt(index)){
                    index++;
                }else {
                    break;
                }
            }
            maxCom = Math.min(maxCom,index);
        }
        return first.substring(0,maxCom);
    }
}
```