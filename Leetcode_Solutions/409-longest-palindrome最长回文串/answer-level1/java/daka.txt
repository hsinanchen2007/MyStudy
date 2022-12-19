### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int chars[] = new int[128];
        for(char ch : s.toCharArray()){
            chars[ch]++;
        }

        int count = 0;
        for(int i = 0; i < 128; i++){
            count += chars[i] - (chars[i] & 1);
        }
        return count < s.length()? (count+1) : s.length();
    }
}
```