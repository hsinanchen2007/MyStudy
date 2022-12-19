```
class Solution {
    public int minimumLengthEncoding(String[] words) {
        int len = words.length;
        Arrays.sort(words, (s1, s2) -> (s2.length() - s1.length()));
        StringBuilder sb = new StringBuilder();
        sb.append(words[0] + "#");
        int size = sb.length();
        for (int i = 1; i < words.length; i++) {
            if (sb.indexOf(words[i] + "#") < 0) {
                size += words[i].length() + 1;
                sb.append(words[i] + "#");
            }
        }
        return size;
    }
}
```
