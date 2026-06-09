```java
public static int strStr(String haystack, String needle) {
        int pos = -1;
        if (needle.equals("")) {
            return 0;
        }
        if (haystack.equals("")) {
            return -1;
        }
        int i = 0, j = 0;
        while (i < haystack.length() && j < needle.length()) {
            if (haystack.charAt(i) == needle.charAt(j)) {
                j++;
                i++;
                if (j == needle.length()) {
                    pos = i - j;
                    break;
                }
            }else{
                i = i - j + 1;
                j = 0;
            }
        }
        return pos;
    }
```
