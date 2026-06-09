### 解题思路
    使用双下标左右两端向中间相向比较；
    一旦遇到第一个左右不相等，就开始另一种比较方式：当前的左 + 1后继续相向比较，或者
    当前的右 - 1后继续相向比较（参考官方题解思路后设计），满足一个能成立，就返回true；

### 代码

```java
class Solution {
    public boolean validPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s.charAt(left) == s.charAt(right)) {
                left++;
                right--;
                continue;
            } 
            break;
        }
        return isEqualChar(s, left + 1, right) || isEqualChar(s, left, right - 1);
        // return isEqualChar(s, 0, s.length() - 1);
    }

    private boolean isEqualChar(String s, int left, int right) {
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}
```