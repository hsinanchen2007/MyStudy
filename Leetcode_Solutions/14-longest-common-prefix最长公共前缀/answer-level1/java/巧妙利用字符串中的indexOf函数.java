### 解题思路
利用字符串的indexOf函数来寻找是否包含相同字符，如果不包含返回-1，包含的话返回索引值。
时间复杂度是O(strs.length)

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length==0){
            return "";
        }
        String prefix = strs[0];
        
        for(int i=1; i< strs.length; i++)
            while(strs[i].indexOf(prefix)!=0){
                prefix = prefix.substring(0, prefix.length()-1);
                if(prefix.isEmpty()) return "";
            }
        return prefix;
    }
}
```