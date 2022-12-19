### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0){return "";}
        //假设第一个字符串为最长公共前缀
        String pre = strs[0];
        for(int i = 1;i<strs.length;i++){
            //当两个字符串不匹配时,缩短最长公共前缀
            while(strs[i].indexOf(pre) !=0 ){
                if(pre.length() == 0){return "";}
                pre = pre.substring(0,pre.length()-1);
            }

       } 
       return pre;
    }
}
```