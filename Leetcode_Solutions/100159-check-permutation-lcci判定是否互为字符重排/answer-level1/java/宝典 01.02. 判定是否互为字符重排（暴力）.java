### 解题思路
无脑暴力比较，只要S2中所有字符出现的此数和S1相同即可

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
         if(s1.length()!=s2.length()) return false;
         for(int i=0;i<s2.length();i++){
             char c= s2.charAt(i);
             int n=0;
             for(int k=0;k<s2.length();k++){
                 if(c==s2.charAt(k))n=n+1;
             }
             int m=0;
             for(int j=0;j<s1.length();j++){
                 if(c==s1.charAt(j))m=m+1;
             }
             if(n!=m) return false;
         }
         return true;
    }
}
```