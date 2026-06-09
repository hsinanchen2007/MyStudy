### 解题思路
此处撰写解题思路

思路：维持 [start, end] 直接是没有重复字符串就可以，出现重复pos+1;


### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int start = 0;
        int end = 0;
        int res = 0;
        while(end < s.length()) {
            int pos = s.indexOf(s.charAt(end), start);
            if (pos < end) {
                start = pos + 1;
            }
            res = Math.max(end - start+1, res);
            end++;
        }
        return res;
    }
}
```