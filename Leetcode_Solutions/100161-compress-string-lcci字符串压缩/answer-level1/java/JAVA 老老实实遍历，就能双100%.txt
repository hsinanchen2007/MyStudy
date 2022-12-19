### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String compressString(String S) {
        
        if (null == S || S.length() < 3)
            return S;
        
        StringBuilder sb = new StringBuilder();

        final char HEAD = '-';
        char before = HEAD;
        int cnt = 0;
        for (char c: S.toCharArray()) {
            if (before == HEAD) {
                before = c;
                cnt = 1;
                continue;
            }

            if (before == c)
                ++cnt;
            else {
                sb.append(before);
                sb.append(cnt);

                cnt = 1;
                before = c;
            }
        }

        if (before != HEAD) {
            sb.append(before);
            sb.append(cnt);
        }
        return sb.length() > S.length() ? S : sb.toString();

    }
}
```