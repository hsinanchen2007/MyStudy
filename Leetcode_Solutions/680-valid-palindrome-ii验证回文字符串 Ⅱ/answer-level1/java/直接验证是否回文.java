### 解题思路
一开始想得太复杂，通过求最长回文子序列的长度进行判断，结果超时了，因为是O(N^2)复杂度。
后来才想到，可以直接从首位两端往中间直接验证回文性，遇到不相等的一对字符时，判断去掉其中一个字符时，剩下的字符串继续匹配能否形成回文串，这就变成O(N)时间复杂度，实现也非常简单

### 代码

```java
class Solution {
    public boolean validPalindrome(String s) {
        int lo = 0, hi = s.length() - 1;
        while (lo <= hi){
            if (s.charAt(lo) == s.charAt(hi)){
                lo++;
                hi--;
            } else {
                if (check(s, lo + 1, hi) || check(s, lo, hi - 1))
                    return true;
                return false;
            }
        }
        return true;
    }

    private boolean check(String s, int lo, int hi){
        while (lo <= hi){
            if (s.charAt(lo++) != s.charAt(hi--))
                return false;
        }
        return true;
    }
}
```