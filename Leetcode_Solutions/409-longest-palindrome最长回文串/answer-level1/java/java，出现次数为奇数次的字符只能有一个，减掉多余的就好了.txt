### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int[] count = new int[123];
        int ans = 0;
        for(char ch: s.toCharArray()){
            count[ch]++;
        }

        for(int c: count){
            ans += (c%2);
        }
        return ans == 0?s.length() : (s.length() - ans + 1);
    }
}
```