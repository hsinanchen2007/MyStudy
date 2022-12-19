1. 先比较A从开头到某一位和B从某一位到结尾是否相等. 如果走到B的结尾时不满足条件, 返回false.
2. 比较A剩余到结尾和B开头的内容是否相等. 相等时返回true, 否则返回false.

```java
    public boolean rotateString(String A, String B) {
        if (A.length() != B.length()) {
            return false;
        }

        int i = 0, j = 0;
        int startB = 0;
        boolean isFound = true;
        while (j < B.length()) {
            isFound = A.charAt(i) == B.charAt(j);
            if (isFound) {
                i++;
                j++;
            } else {
                i = 0;
                j = ++startB;
            }
        }
        if (!isFound) {
            return false;
        }

        for (j = 0; i < A.length(); i++, j++) {
            if (A.charAt(i) != B.charAt(j)) {
                return false;
            }
        }
        return true;
    }
```
