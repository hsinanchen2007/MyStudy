### 解题思路
本题和344题和125题属于同类型题目,但是我在解决这类问题的内存消耗比较大，因为额外建了很多不必要的空间，希望有大佬指点一下。

### 代码

```java
class Solution {
    public String reverseVowels(String s) {
        if (s == null || s.length() == 0) {
            return s;
        }
        char[] str = s.toCharArray();
        int left = 0;
        int right = str.length - 1;
        while (left < right) {
            char lChar = str[left];
            if (!isVowel(lChar)) {
                left++;
                continue;
            }
            char rChar = str[right];
            if (!isVowel(rChar)) {
                right--;
                continue;
            }
            char tmp = lChar;
            str[left] = str[right];
            str[right] = tmp;
            left++;
            right--;
        }
        return convertArrToStr(str);
    }

    private String convertArrToStr(char[] s) {
        StringBuilder str = new StringBuilder();
        for (int i = 0; i < s.length ; i++) {
            str.append(s[i]);
        }
        return str.toString();
    }

    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
                || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
}
```