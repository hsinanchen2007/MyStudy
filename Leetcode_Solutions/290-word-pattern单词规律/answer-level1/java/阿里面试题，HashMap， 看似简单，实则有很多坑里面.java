### 解题思路

总体思路是hashmap，很简单，细节需要注意

比如说在判断m.containsKey(cur) 和 !m.get(cur).equals(s[i]) 不能连在一块写

if else 写的时机，放入map中的时机都不能出错
### 代码

```java
class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] s = str.split(" ");
        if (s.length != pattern.length()) {
            return false;
        }
        Map<Character, String> m = new HashMap<>();
        for (int i = 0; i < pattern.length(); i ++) {
            char cur = pattern.charAt(i);
            if (m.containsKey(cur)) {
                if (!m.get(cur).equals(s[i])) return false;
            } else {
                if (m.containsValue(s[i])) return false;
                m.put(cur, s[i]);
            } 
        }
        return true;
    }
}
```