```
public String countAndSay(int n) {
        String result = "1";
        // 执行n-1次循环（因为n=1时直接可返回结果1）
        for (int i = 1; i < n; i++) {
            // 从左到右扫描上次循环得到的字符串，找到连续相同的1或者2的个数
            char[] chars = result.toCharArray();
            StringBuilder stringBuilder = new StringBuilder();
            for (int j = 0; j < chars.length; j++) {
                char c = chars[j];
                int count = 1;
                while (j < chars.length - 1) {
                    if (c == chars[j + 1]) {
                        j++;
                        count++;
                        continue;
                    } else {
                        break;
                    }
                }
                stringBuilder.append(count).append(c);
            }
            result = stringBuilder.toString();
        }
        return result;
    }
```
