# 用StringBuilder来做，首先将给定字符串通过split()方法用空格分隔开来，得到字符串数组，然后遍历数组，对于每次遍历，先append一个空格，再append字符串
# reverse的结果，最后将结果中的第一个空格去掉即可。
```
    public String reverseWords(String s) {
        if (s == null || s.length() <= 0) return s;
        String[] arr = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for (String str : arr) {
            sb.append(" ");
            sb.append(new StringBuilder(str).reverse());
        }
        return sb.substring(1);
    }
```
