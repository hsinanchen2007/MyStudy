### 解题思路
Java打卡

### 代码

```java
class Solution {
    public String compressString(String S) {
        if (S == null || S.length() == 0)
            return S;
        char[] chars = S.toCharArray();
        int n = chars.length;
        char cur = S.charAt(0);
        int count = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (chars[i] == cur) {
                count++;
            } else {
                sb.append(cur);
                sb.append(count);
                cur = chars[i];
                count = 1;
            }
        }
        
        sb.append(cur);
        sb.append(count);
        
        String s = sb.toString();
        if (s.length() >= S.length()) {
            return S;
        }
       
        return s;

    }
}
```