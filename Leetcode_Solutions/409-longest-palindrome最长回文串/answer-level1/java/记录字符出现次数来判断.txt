### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int[] cnt= new int[58];
        for(char c : s.toCharArray()){
            cnt[c - 'A'] += 1;
        }

        int ans = 0;
        for (int x:cnt){
            ans += x-(x&1);
        }

        return ans < s.length()? ans+1:ans;

    }
}
```