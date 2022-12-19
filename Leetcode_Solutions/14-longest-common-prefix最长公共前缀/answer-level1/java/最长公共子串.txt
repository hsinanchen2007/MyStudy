### 解题思路
大神思路复现
主要是先通过第一个字符串与第二个字符串找到两者的公共子串，然后通过这个公共子串与下一个字符串进行比较寻找两者的公共字符串，依次下去就是整个的最长公共子串

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {

        if(strs.length==0){
            return "";
        }
        String a = strs[0];
        int min = 0;
        for (int i = 1;i<strs.length;i++){
            int j = 0;
            for (;j<a.length()&&j<strs[i].length();){
                if(a.charAt(j)!=strs[i].charAt(j)){
                    break;
                }
                j++;
            }
            a = a.substring(0,j);
            if(a==""){
                return "";
            }
        }
       return a;
    }
}
```