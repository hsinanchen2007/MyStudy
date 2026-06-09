## 思路
1. 外层循环遍历字符串数组
2. 内层循环遍历字符数组，使用StringBuilder来append字符，内层循环时需要关注4种状态
   - 遇到@符号时：使用append变量标记，代表之后无论遍历到什么字符都append
   - 未遇到@符号时：
        - 第一次遇到+符号时：使用ignore变量标记，代表除非遇见@符号切换状态到1，否则忽略之后的所有字符
        - 遇到.符号时：代表除非遇见@符号切换状态到1，否则忽略该字符
        - 遇到普通字符时：直接append
3. 内层循环结束，把字符串放入set去重
4. 外层循环结束，返回set的长度
## 代码
```java []
class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> set = new HashSet<>();

        for (String email : emails) {
            boolean ignore = false;
            boolean append = false;
            StringBuilder sb = new StringBuilder();
            for (char c: email.toCharArray()) {
                if (append) {
                    sb.append(c);
                } else {
                    if (c == '@') {
                        sb.append(c);
                        append = true;
                        continue;
                    }

                    if (ignore || c == '.') {
                        continue;
                    }

                    if (c == '+') {
                        ignore = true;
                        continue;
                    }

                    sb.append(c);
                }
            }

            set.add(sb.toString());
        }

        return set.size();
    }
}
```
