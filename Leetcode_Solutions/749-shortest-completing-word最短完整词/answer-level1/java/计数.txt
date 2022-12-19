```java
class Solution {
    public String shortestCompletingWord(String licensePlate, String[] words) {
        String ans = null;
        int[] count = new int[26];
        for (char c : licensePlate.toCharArray()) {
            c = Character.toLowerCase(c);
            if (c >= 'a' && c <= 'z') {
                count[c - 'a']++;
            }
        }
        for (String word : words) {
            int[] copy = Arrays.copyOf(count, count.length);
            for (char c : word.toCharArray()) {
                int idx = c - 'a';
                copy[idx]--;
            }
            if (ans == null || ans.length() > word.length()) {
                boolean flag = true;
                for (int i : copy) {
                    if (i > 0) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ans = word;
                }
            }
        }
        return ans;
    }
}
```
