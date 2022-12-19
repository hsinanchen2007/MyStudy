### 解题思路


### 代码

```java
import java.util.Map.Entry;
class Solution {
    public int longestPalindrome(String s) {
        HashMap<Character, Integer> hs = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            hs.compute(s.charAt(i), (key, val) -> val == null ? 1 : val + 1);
            // if (!hs.containsKey(s.charAt(i))) {
            //     hs.put(s.charAt(i), 1);
            // } else {
            //     hs.put(s.charAt(i), hs.get(s.charAt(i)) + 1);
            // }
        }
        int max = 0;
        int len = 0;
        for (Entry<Character, Integer> en : hs.entrySet()) {
            len += en.getValue() - en.getValue() % 2;
            // if (en.getValue() % 2 == 0) {
            //     len += en.getValue();
            // } else  {
            //     len += en.getValue() - 1;
            // }
        }
        return len < s.length() ? len + 1 : len;
    }
}

```