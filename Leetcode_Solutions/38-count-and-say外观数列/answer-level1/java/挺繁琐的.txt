### 代码

```java
class Solution {
    public String countAndSay(int n) {
        String last = "1";
        if (n == 1) {
            return last;
        }
        --n;
        while(n-- > 0) {
            StringBuilder next = new StringBuilder();
            for (int i = 0; i < last.length();) {
                int j = i;
                while(j + 1 < last.length()
                        && last.charAt(j) == last.charAt(j + 1)) {
                    ++j;
                }
                next.append(j - i + 1);
                next.append(last.charAt(i));
                i = j + 1;
            }
            last = next.toString();
        }
        return last;
    }
}
```