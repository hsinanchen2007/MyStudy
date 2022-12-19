### 解题思路
此处撰写解题思路
双指针，左指针从0开始，右指针从length-1开始，
如果不是要比较的内容（数字或者字母），则移动指针；
如果指向的值不等，则返回false;
否则左指针加1，右指针减1.
<b>不过这个解法效率太低了。。。</b>


### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
        if (s == null || s.trim().length() == 0) {
            return true;
        }
        s = s.toLowerCase(); // 因为不考虑大小写，全部默认小写
        int left = 0;
        int right = s.length() - 1;
        while (left <= right) {
            char lChar = s.charAt(left);
            while (lChar < '0' || lChar > '9' && lChar < 'a' || lChar > 'z') {
                left ++;
                if (left > right) {
                    return true;
                }
                lChar = s.charAt(left);
            }
            char rChar = s.charAt(right);
            while (rChar < '0' || rChar > '9' && rChar < 'a' || rChar > 'z') {
                right --;
                if (right < left) {
                    return true;
                }
                rChar = s.charAt(right);
            }
            if (lChar != rChar) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}
```