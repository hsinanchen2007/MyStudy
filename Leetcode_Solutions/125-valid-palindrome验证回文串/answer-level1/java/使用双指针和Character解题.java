### 解题思路

通过`i`两个指针`j`，通过`charAt()`原位比较：

1. 使用`Character.isLetterOrDigit`判断字母和数字
2. 使用`Character.toLowerCase`进行大小写转换

### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (!Character.isLetterOrDigit(s.charAt(i))) {
                i += 1;
                continue;
            }
            if (!Character.isLetterOrDigit(s.charAt(j))) {
                j -= 1;
                continue;
            }
            if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j))) {
                return false;
            }
            i += 1;
            j -= 1;
        }
        return true;
    }
}
```