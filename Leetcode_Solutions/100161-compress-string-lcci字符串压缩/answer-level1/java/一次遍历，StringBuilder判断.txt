一次遍历。
遍历字符串，比较当前字符 与 builder的最后一个字符是否相同？ 
if 相同，计数器count自增，统计连续字符的个数；
else 否则builder的末尾添加统计次数、添加新的字符，重置计数器count。
注意判断特殊条件（字符串为空）。
```
public String compressString(String S) {
        if (S.isEmpty()) {
            return S;
        }
        StringBuilder builder = new StringBuilder();
        builder.append(S.charAt(0));
        int count = 1;
        for (int i = 1; i < S.length(); ++i) {
            if (builder.charAt(builder.length() - 1) == S.charAt(i)) {
                ++count;
            } else {
                builder.append(count);
                count = 1;
                builder.append(S.charAt(i));
            }
        }
        builder.append(count);
        return builder.length() >= S.length() ? S : builder.toString();
    }
```
