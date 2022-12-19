```
public String addBinary(String a, String b) {
        if (a == null || a.length() == 0) {
            return b;
        }
        if (b == null || b.length() == 0) {
            return a;
        }
        if (a.length() < b.length()) {
            return addBinary(b, a);
        }
        int len = a.length() + 1;
        char[] newCharArray = new char[len];
        int flag = 0;
        int num = 0;
        int gap = a.length() - b.length();
        for (int i = a.length() - 1; i >= gap; i--) {
            num = flag + a.charAt(i) + b.charAt(i - gap) - '0' * 2;
            newCharArray[--len] = num % 2 == 0 ? '0' : '1';
            flag = num / 2;
        }
        for (int i = gap - 1; i >= 0; i--) {
            num = flag + a.charAt(i) - '0';
            newCharArray[--len] = num % 2 == 0 ? '0' : '1';
            flag = num / 2;
        }
        if (flag == 1) {
            newCharArray[0] = '1';
        }
        if (newCharArray[0] == '1') {
            return new String(newCharArray);
        }
        return new String(newCharArray, 1, a.length());

    }
```
