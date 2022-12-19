### 解题思路
分别从左右两端开始遍历字符串，某一边遇到不是数字或者字母的字符就跳过；
都为字母或者数字就进行比较，若遇到不同的，则代表不是回文串；
通过上述检查的，判定为是回文串
（执行用时 :3 ms, 在所有 Java 提交中击败了94.65%的用户
内存消耗 :39.6 MB, 在所有 Java 提交中击败了6.87%的用户）

### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
        if (s.length() <= 1) {
            return true;
        }
        s = s.toLowerCase();
        int left = 0;
        int right = s.length()-1;
        while (left < right) {
            char c1 = s.charAt(left);
            char c2 = s.charAt(right);
            boolean needContinue1 = false;
            boolean needContinue2 = false;
            // c1不是数字或者字母，标记跳过
            if (!((c1 >= 'a' && c1 <= 'z') || (c1 >= '0' && c1 <= '9'))) {
                needContinue1 = true;
                left++;
            }
            // c2不是数字或者字母，标记跳过
            if (!((c2 >= 'a' && c2 <= 'z') || (c2 >= '0' && c2 <= '9'))) {
                needContinue2 = true;
                right--;
            }
            // c1或c2有一个不是就跳过
            if (needContinue1 || needContinue2) {
                continue;
            }

            // 都为字母或数字，进行比较
            if (c1 != c2) {
                return false;
            } else {
                left++;
                right--;
            }
        }
        // 若通过检查，则为回文串
        return true;
    }
}
```