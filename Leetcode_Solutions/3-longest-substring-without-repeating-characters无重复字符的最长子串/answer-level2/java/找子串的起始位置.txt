### 解题思路
关键在找子串的起始点
需要考虑当前字符已经存在于构建的字典时，需要重置起始点，但实际上正在遍历的子串不包含当前字符，所以需要考虑起始点移动时不能后退

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.equals("") || s == null) {
            return 0;
        }

        int sum = 0;

        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0, start = 0; i < s.length(); i++) {
            if (map.containsKey(s.charAt(i))) {
                start = Math.max(map.get(s.charAt(i)) + 1, start);
            }
            sum = Math.max(sum, i - start + 1);
            map.put(s.charAt(i), i);
        }

        return sum;
    }
}
```