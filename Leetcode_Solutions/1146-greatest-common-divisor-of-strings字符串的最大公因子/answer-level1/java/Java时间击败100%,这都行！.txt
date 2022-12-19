### 解题思路
递归好啊，写起来真方便

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if(str1 == null || str2 == null)
            return "";
        if(str1.equals(str2))
            return str1;
        if(str1.length() == str2.length())
            return "";
        //如果存在
        String maxStr = str1.length() > str2.length() ? str1 : str2;
        String minStr = maxStr.equals(str1) ? str2 : str1;
        if(!maxStr.substring(0, minStr.length()) .equals(minStr))
            return "";
        return gcdOfStrings(maxStr.substring(minStr.length(), maxStr.length()), minStr);
    }
}
```