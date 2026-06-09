```
    public int myAtoi(String str) {
        long flag = -1, result = 0;
        for (int i = 0; i < str.length(); i++) {
            long l = flag == -1 ? str.charAt(i) == '+' || str.charAt(i) == '-' ? flag = str.charAt(i) : str.charAt(i) != ' ' ? flag = i-- : -1 : !Character.isDigit(str.charAt(i)) || result > Integer.MAX_VALUE ? i = str.length() : (result = result * 10 + (str.charAt(i) - '0'));
        }
        return flag == '-' ? -result < Integer.MIN_VALUE ? Integer.MIN_VALUE : (int) (-result) : result > Integer.MAX_VALUE ? Integer.MAX_VALUE : (int) (result);
    }
```


利用语法和结构追求极致行数的奇技淫巧