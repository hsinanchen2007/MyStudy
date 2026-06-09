### 解题思路
同向双指针

### 代码

```java
class Solution {
    public String minWindow(String s, String t) {
        if (t == null || t.length() == 0) {
            return "";
        }
        int min = Integer.MAX_VALUE;
        int start = -1;

        int[] rest = new int[256];
        int[] ress = new int[256];

        int i = 0; //左指针
        int c = 0; //不同字符的数量

        for (char ch : t.toCharArray()) {
            rest[ch]++;
            if (rest[ch] == 1) {
                c++;
            }
        }

        for (int j = 0; j < s.length(); j++) {
            ress[s.charAt(j)]++;
            if (ress[s.charAt(j)] == rest[s.charAt(j)]) {
                c--;
            }

            while (c == 0) {
                if (j - i + 1 < min) {
                    min = j - i + 1;
                    start = i;
                }

                ress[s.charAt(i)]--;
                if (ress[s.charAt(i)] == rest[s.charAt(i)] - 1) {
                    c++;
                }
                i++;
            }

        }

        return start == -1 ? "" : s.substring(start, start + min);
    }
}
```