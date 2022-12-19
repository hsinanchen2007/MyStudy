### 代码

```java
class Solution {
    public char findTheDifference(String s, String t) {
        Map<Character, Integer> map = new HashMap<>();
        
        for(int i =0; i < s.length(); ++i) {
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
        }

        for(int i = 0; i < t.length(); ++i) {
            if (!map.containsKey(t.charAt(i))) {
                return t.charAt(i);
            }
            int count = map.get(t.charAt(i));
            if (--count < 0) {
                return t.charAt(i);
            }
            map.put(t.charAt(i), count); 
        }
        return ' ';
    }
}
```