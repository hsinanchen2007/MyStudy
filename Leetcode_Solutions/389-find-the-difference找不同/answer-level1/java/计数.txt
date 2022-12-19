```java
class Solution {
    public char findTheDifference(String s, String t) {
        int[] map = new int[26];
        for (int i = 0; i < s.length(); i++) {
            map[s.charAt(i) - 'a']++;
            map[t.charAt(i) - 'a']--;
        }
        map[t.charAt(t.length() - 1) - 'a']--;
        int i;
        for (i = 0; i < map.length; i++) {
            if (map[i] < 0) {
                break;
            }
        }
        return (char) ('a' + i);
    }

}
```
