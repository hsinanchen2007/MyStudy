字符串`右对齐`进行相加
```java
class Solution {

    public String addBinary(String a, String b) {
        if (a.length() < b.length()) {
            String temp = a;
            a = b;
            b = temp;
        }

        char[] cha = a.toCharArray();
        char[] chb = b.toCharArray();
        int gap = cha.length - chb.length;
        int k = 0;

        for (int i = cha.length - 1; i >= 0; i--) {
            int n = getInt(cha[i]) + k;
            k = 0;
            if (i - gap >= 0) {
                n += getInt(chb[i - gap]);
            }
            if (n >= 2) {
                k = 1;
                cha[i] = getChar(n - 2);
            } else {
                cha[i] = getChar(n);
            }
        }
        String result = String.valueOf(cha);
        if (k > 0) {
            result = "1" + result;
        }
        return result;
    }

    private int getInt(char ch) {
        return ch == '0' ? 0 : 1;
    }
    
    private char getChar(int i) {
        return i == 1 ? '1' : '0';
    }

}
```