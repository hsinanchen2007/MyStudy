### 解题思路
定义前后指针i和j，当i，j位置元素相等，计数器加1，且j指针往后走；如果不相等，则把i位置的元素拼接字符串，并且把i指针指向j位置，j位置往后加1，同时重置计数器count。

### 代码

```java
class Solution {
    public String compressString(String S) {
        if (S == null || S.length() == 0) {
            return S;
        }
        int i = 0, j = 1;
        int count = 1;
        StringBuilder str = new StringBuilder();
        while (j < S.length()) {
            if (S.charAt(i) == S.charAt(j)) {
                count++;
                j++;
            } else {
                str.append(S.charAt(i)).append(count);
                i = j;
                j++;
                count = 1;
            }
        }
        str.append(S.charAt(i)).append(count);

        return str.length() >= S.length() ? S : str.toString();
    }
}
```