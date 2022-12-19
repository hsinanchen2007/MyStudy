### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
        if(s.length() == 0) return false;
        int[] chars = new int[128];
        for(int i = 0; i < s.length(); i++) {
            chars[s.charAt(i)] += 1;
        }
        int size = 0;
        for(int j = 0; j < chars.length; j++) {
            if(chars[j] % 2 == 1) size += 1;
            if(size > 1) return false;
        }
        return true;
    }
}
```