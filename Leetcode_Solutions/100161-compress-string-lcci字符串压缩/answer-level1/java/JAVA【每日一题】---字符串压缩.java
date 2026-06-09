先转换，再比较长度

使用lastChar记录上一个重复字符，count计数，当遇到不同的字符时拼进StringBuilder中

最后记得把最后一个字符和计数加进去

```
    public String compressString(String S) {
        if (S == null || S.length() == 0) {
            return S;
        }
        StringBuilder sb = new StringBuilder();
        int count = 1;
        char lastChar = S.charAt(0);
        if (S.length() == 1) {
            return S;
        }
        for (int i = 1; i < S.length(); i++) {
            char c = S.charAt(i);
            if (lastChar == c) {
                count++;                
            } else {
                sb.append(lastChar).append(count);
                lastChar = c;
                count = 1;
            }
        }
        sb.append(lastChar).append(count);
        if (sb.length() >= S.length()) {
            return S;
        }
        return sb.toString();
    }
```