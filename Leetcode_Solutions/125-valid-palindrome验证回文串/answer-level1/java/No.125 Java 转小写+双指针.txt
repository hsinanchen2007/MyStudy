```
public boolean isPalindrome(String s) {
        if (s.isEmpty()) {
            return true;
        }
        char[] chars = s.toLowerCase().toCharArray();
        for (int leftIndex = 0, rightIndex = s.length() - 1 - leftIndex; leftIndex < s.length() && rightIndex > 0; ){
            char leftChar = chars[leftIndex];
            char rightChar = chars[rightIndex];
            if (!(leftChar <= 'z' && leftChar >= 'a' || leftChar <= '9' && leftChar >= '0')) {
                leftIndex++;
            } else if (!(rightChar <= 'z' && rightChar >= 'a' || rightChar <= '9' && rightChar >= '0')) {
                rightIndex--;
            } else if (leftChar != rightChar) {
                return false;
            } else {
                leftIndex++;
                rightIndex--;
            }
        }
        return true;
    }
```
