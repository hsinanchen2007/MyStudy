

```java
class Solution {
    public String compressString(String s) {
        int l = s.length();
        if (l <= 2) {
            return s;
        }
        char prev = 0; // ASCII中表示空字符串
        int count = 0;
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (count == 0) {
                prev = c;
                ++count;
            } else if (prev == c) {
                ++count;
            } else {
                sb.append(prev).append(count);
                prev = c;
                count = 1;
            }
        }
        sb.append(prev).append(count);
        return sb.length() < l ? sb.toString() : s;
    }
}
```
