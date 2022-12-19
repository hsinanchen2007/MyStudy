时间复杂度为`O（N）`：

```
    /**
     * 有效回文串
     *
     * @param s
     * @return
     */
    public boolean isPalindrome(String s) {
        char[] ss = s.toCharArray();
        int left = 0, right = ss.length - 1;
        while (left < right) {
            if (!Character.isLetterOrDigit(ss[left])) {
                left++;
                continue;
            }
            if (!Character.isLetterOrDigit(ss[right])) {
                right--;
                continue;
            }
            if (Character.toLowerCase(ss[left]) != Character.toLowerCase(ss[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
```
