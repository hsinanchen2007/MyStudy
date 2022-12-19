### 解题思路
没啥好思路，直接遍历就好了。

### 代码

```java
class Solution {
    public String compressString(String S) {
        if(S == null || S.length() == 0 || S.length() == 1) {
            return S;
        }

        int len = S.length();
        int cnt = 1;

        StringBuilder sb = new StringBuilder();
        for (int i = 1; i < len; i++) {
            if(S.charAt(i) != S.charAt(i - 1)) {
                sb.append(S.charAt(i - 1)).append(cnt);
                cnt = 1;
            } else {
                cnt++;
            }
        }

        sb.append(S.charAt(len - 1)).append(cnt);
        return sb.length() < S.length() ? sb.toString() : S;
    }
}
```