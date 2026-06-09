### 解题思路
最长回文串，就是原长度减去奇数字符多出来的一个字符
如果没有奇数字符，那字符串的最大长度就是原字符长度
### 代码

```java


class Solution {
    public int longestPalindrome(String s) {
        int [] nums = new int [128];
        char[] chars = s.toCharArray();
        for (char c:chars) {
            nums[c]++;
        }

        int length = s.length();
        int SinguarCharOfNum =0;
        for (int num:nums){
            if (num%2 == 1){
                SinguarCharOfNum++;
            }
        }
        if (SinguarCharOfNum!=0) {
            length = length - SinguarCharOfNum + 1;
        }
        return length;
    }
}

```