### 解题思路
此处撰写解题思路
滑动窗口，通俗易懂。其他类似的都可以用此框架，稍作改动。

执行用时 :
11 ms
, 在所有 Java 提交中击败了
39.60%
的用户
内存消耗 :
41.3 MB
, 在所有 Java 提交中击败了
100.00%
的用户


### 代码

```java
class Solution {
 /**
     * 滑动窗口
     * 
     * @param s
     * @return
     */
    public int lengthOfLongestSubstring(String s) {

        if (s == null || s.isEmpty()) {
            return 0;
        }
        int left = 0;
        int right = 0;
        HashMap<Character, Integer> windows = new HashMap<>();
        int maxLen = 0;
        boolean isMatch = false;
        while (right < s.length()) {
            char c = s.charAt(right);
            int count = windows.getOrDefault(c, 0);
            windows.put(c, count + 1);
            if ( windows.getOrDefault(c, 0) > 1) {
                isMatch = true;
            }
            right++;

            while (isMatch) {
                char c1 = s.charAt(left);
                int value = windows.getOrDefault(c1, 0);
                if (value == 1) {
                    windows.remove(c1);
                } else if (value > 1) {
                    windows.put(c1, value - 1);
                    isMatch = false;
                }
                left++;
            }
            maxLen = Math.max(maxLen, right - left);
        }
        return maxLen;
    }
}
```