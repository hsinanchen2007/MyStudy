```
    public static int reverse(int x) {
        StringBuilder str = new StringBuilder(String.valueOf(x)).reverse();
        if (str.toString().endsWith("-")) {
            str.deleteCharAt(str.length() - 1);
            str.insert(0, "-");
        }
        try {
            Integer.parseInt(str.toString());
            return Integer.parseInt(str.toString());
        } catch (NumberFormatException e) {
            return 0;
        }
    }
```
直接反转 最后一位是 "-" 直接删除 并在最前面加上 "-"
得到结果直接转化