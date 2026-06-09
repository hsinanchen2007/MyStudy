```
public boolean isPalindrome(String s) {
        char[] chars = s.toCharArray();
        int left = 0, right = chars.length - 1;
        while (left < right) {
            if (!Character.isLetterOrDigit(chars[left])) {
                left++;
                continue;
            }
            //直接判断是否为字母/数字
            if (!Character.isLetterOrDigit(chars[right])) {
                right--;
                continue;
            }
            if (Character.toLowerCase(chars[left]) != Character.toLowerCase(chars[right]))
                return false;
            else {
                left++;
                right--;
            }
        }
        return true;
    }
```

