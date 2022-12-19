正则来一发
```
    public int myAtoi(String str) {
        str = str.trim();
        Pattern pattern = Pattern.compile("^(\\+|-)?\\d+");
        Matcher matcher = pattern.matcher(str);
        int res = 0;
        while (matcher.find()) {
            str = matcher.group();
            if (str.startsWith("+")) {
                str = str.replaceFirst("\\+", "");
            }
            try {
                res = Integer.parseInt(str);
            } catch (NumberFormatException e) {
                if (str.startsWith("-")) {
                    return Integer.MIN_VALUE;
                } else {
                    return Integer.MAX_VALUE;
                }
            }
            return res;
        }
        return 0;
    }
```
