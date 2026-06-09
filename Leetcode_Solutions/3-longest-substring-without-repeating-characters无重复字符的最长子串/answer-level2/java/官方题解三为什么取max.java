### 解题思路
详细解释了官方题解三为什么取max，8ms，41.7M
### 代码

```java
class Solution {
    Map<Character, Integer> map = new HashMap<>();
    int maxLen=0;
    public int lengthOfLongestSubstring(String s) {
        char[] str = s.toCharArray();
        int slow=0, fast=0;
        while (fast < s.length()) {
            char c = str[fast];
            if(map.containsKey(c)){
                int pos = map.get(c);
                slow = slow <= pos ? pos + 1 : slow;//把官方题解三max改造如此,slow比hashset里的更靠后时不用动
            }
            int curLen = fast-slow+1;
            maxLen = maxLen < curLen ? curLen : maxLen;
            map.put(c, fast);
            fast++;
        }
        return maxLen;
    }
}
```