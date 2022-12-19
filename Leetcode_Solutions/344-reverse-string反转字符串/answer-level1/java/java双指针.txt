执行用时 :2 ms, 在所有 Java 提交中击败了98.52%的用户
内存消耗 :54.7 MB, 在所有 Java 提交中击败了61.38%的用户
```
    public static void reverseString(char[] s) {
        char temp = ' ';
        for (int i = 0; i < s.length / 2; i++) {
            temp = s[i];
            s[i] = s[s.length - i - 1];
            s[s.length - i - 1] = temp;
        }
    }
```
