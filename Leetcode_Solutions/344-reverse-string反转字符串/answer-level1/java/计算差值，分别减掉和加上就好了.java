想法就是计算对称位置的字符的值的差，分别加上和减去就好了
```
public void reverseString(char[] s) {
        if (s == null || s.length == 0) return;
        int left = 0, right = s.length - 1;
        while (left < right) {
            int diff = s[left] - s[right];
            s[left] = (char)(s[left] - diff);
            s[right] = (char)(s[right] + diff);
            left++;
            right--;
        }
    }
```
