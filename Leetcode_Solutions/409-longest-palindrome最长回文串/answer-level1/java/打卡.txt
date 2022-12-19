### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int[] charCount = new int[52];
        for (char ch : s.toCharArray()) {
            if ((ch >= 'A') && (ch <= 'Z')) {
                charCount[ch - 'A']++;
            }
            if ((ch >= 'a') && (ch <= 'z')) {
                charCount[ch - ('a' - 'Z') - 'A']++;
            }
        }
        int ans = 0;
        boolean single = false;
        for (int count : charCount) {
            if ((count % 2) == 0) {
                ans += count;
            } else {
                ans += count - 1;
                if (!single) {
                    ans++;
                    single = true;
                }
            }
        }
        return ans;
    }
}
```