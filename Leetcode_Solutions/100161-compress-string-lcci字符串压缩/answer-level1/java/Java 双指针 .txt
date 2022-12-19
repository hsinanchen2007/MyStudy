小知识：
（1）使用String.toCharArray()方法，用char[] 代替 String.charAt()可提高程序运行速度。
（2）使用StringBuilder替换String的"+",提高性能，避免产生过多的对象。
```java
public class CompressString {
    public String compressString(String S) {
        StringBuilder builder = new StringBuilder();
        //使用String.toCharArray()可提高效率
        char[] chars = S.toCharArray();
        int p;
        for (int i = 0; i <chars.length ; i = p) {
            char c = chars[i];
            p = i;
            while (p < S.length() && chars[p] == c)
                p ++;
            int n = p - i;
            builder.append(c).append(n);
        }
        String compressed = builder.toString();
        return compressed.length() < S.length() ? compressed : S;
    }
}
```
