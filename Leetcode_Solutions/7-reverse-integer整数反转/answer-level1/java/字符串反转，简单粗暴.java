```
public int reverse(int x) {
        String s;
        if (x < 0) {
            s = "-" + new StringBuffer(String.valueOf(x*-1)).reverse().toString();
        } else {
            s = new StringBuffer(String.valueOf(x)).reverse().toString();
        }
        int k;
        try {
            k = Integer.parseInt(s);
        } catch (Exception e) {
            return 0;
        }
        return k;
    }
```

看到反转第一个想法就是转换字符串，事实证明字符串转换后非常的简单