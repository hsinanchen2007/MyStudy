大致思路就是trim前后空格，正则分割split，后续数组倒序拼接
```
    public String reverseWords(String s) {
        if (s == null || s.isEmpty()) {
            return "";
        }
        String str = s.trim();
        String[] strArr = str.split("\\s+");
        StringBuilder sb = new StringBuilder();
        for (int i = strArr.length - 1; i >= 0; i--) {
            sb.append(strArr[i]);
            if (i > 0) {
                sb.append(" ");
            }
        }
        return sb.toString();
    }
```
这题目难度级别是不是有点问题...