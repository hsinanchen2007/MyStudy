思路：首先确认两个字符串的长度要相等。其次只要保证A+A 的字符串中包含B就可以了。因为A+A已经包含了所有可移动的方案。
```
public static boolean rotateString(String A, String B) {
        return A.length() == B.length() && (A+A).contains(B);
    }

    public static void main(String[] args) {
        String a = "abcde";
        String b = "abced";
        boolean flag = rotateString(a,b);
        System.out.println(flag);
    }
```

    