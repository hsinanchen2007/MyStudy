```
public  String gcdOfStrings(String str1, String str2) {
        int max = gcd(str1.length(), str2.length());
        int times1 = str1.length() / max, times2 = str2.length() / max;
        String value = "";
        if (times1 == times2 && !str1.equals(str2)) {
            return value;
        } else if (repeat(str1.substring(0, max), times1).equals(str1) && repeat(str2.substring(0, max), times2).equals(str2)) {
            value = str1.substring(0, max);
        }
        return value;
    }

    public static int gcd(int p, int q) {
        while (q > 0) {
            int r = p % q;
            p = q;
            q = r;
        }
        return p;
    }

    public static String repeat(String origin, int times) {
        String value = "";
        for (int i = 0; i < times; i++) {
            value += origin;
        }
        return value;
    }
```
