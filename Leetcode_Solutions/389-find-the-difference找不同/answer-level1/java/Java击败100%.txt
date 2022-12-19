<br>
<br>
[简单粗暴，*So easy*🥴]
<br>
<br>
```java
class Solution {
    public char findTheDifference(String s, String t) {
        int[] table = new int[26];
        for (char c : s.toCharArray()) {
            table[c - 'a']++;
        }
        for (char c : t.toCharArray()) {
            table[c - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            int count = table[i];
            if (count == -1) {
                return (char) ('a' + i);
            }
        }
        return '?';
    }
}
```