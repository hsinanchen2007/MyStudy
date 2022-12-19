### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        if (s == null || s.length() <= 0) {
            return 0;
        }
        int maxRes = 0;
        int left = 0;
        int times = 0;
        Map<Character, Integer> map = new HashMap<>();

        for (int i = 0; i< s.length(); i++) {
            char ch = s.charAt(i);
            if (map.containsKey(ch)) {
                times = map.get(ch);
                map.put(ch, ++times);
            } else {
                map.put(ch, 1);
            }
            if (map.isEmpty() || map.size() <= 2) {
                maxRes = Math.max(maxRes, i - left + 1);
            } else if (map.size() > 2) {
                while (map.size() != 2) {
                    char ch1 = s.charAt(left ++);
                    times = map.get(ch1);
                    if (times == 1) {
                        map.remove(ch1);
                    } else {
                        map.put(ch1, --times);
                    }
                }
            }
        }
        return maxRes;
    }
}
```