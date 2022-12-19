### 解题思路
遍历字符串，如果无重复就把值放入map，同时curMax+1。如果重复，则index返回重复的字符串的后一位，并把curMax置为0.

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        char[] chars = s.toCharArray();
        if (chars.length == 0) return 0;
        int max = 1;
        int curMax = 0;
        Map<String, Integer> map = new HashMap();
        int i=0;
        while(i<=chars.length-1){
            if (map.containsKey(String.valueOf(chars[i]))) {
                curMax = 0;
                i =  map.get(String.valueOf(chars[i]))+1;
                map.clear();
            } else {
                curMax += 1;
                max = Math.max(curMax, max);
                map.put(String.valueOf(chars[i]), i++);
            }
        }
        return max;
}
}
```