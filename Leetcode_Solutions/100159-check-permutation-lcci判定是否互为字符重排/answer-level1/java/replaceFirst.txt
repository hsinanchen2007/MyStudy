### 解题思路
先判断字符串长度，长度不同直接返回false，相同则挨个排除，每次排除一个字符，如果最后能排除干净，则返回true

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        if (s1.length() == s2.length()) {
            for (int i=0; i<s1.length(); i++) {
            s2 = s2.replaceFirst(String.valueOf(s1.charAt(i)), "");
            }
            if (s2.equals("")) {
                return true;
            }
        }
        return false;
    }
}
```