### 解题思路
此处撰写解题思路
首先筛选出字符串数组中字符串长度最短的长度samlllen，使用substring方法截取首个字符串【0，smalllen）作为一个新的字符串，与字符串数组中所有元素对比。
### 代码

```java
class Solution {
    public  String longestCommonPrefix(String[] strarr){
        //如果字符串长度是，内容为空，前缀为空
        if(strarr.length==0){ return ""; }
        //获取所有字符换中最短的长度
        int smalllen  = strarr[0].length();

        for (int i = 0; i < strarr.length; i++) {
            smalllen = smalllen<strarr[i].length()?smalllen:strarr[i].length();
        }
        String newstr = strarr[0].substring(0,smalllen);
        while (smalllen>0) {
            for (int j = 0; j < strarr.length; j++) {
                if (!strarr[j].startsWith(newstr)) {
                   break;
                }
                if(j==strarr.length-1){
            return newstr;
                }
            }
            smalllen--;
            newstr = newstr.substring(0,smalllen);
        }
        return "";
    }
}
```