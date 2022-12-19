### 解题思路
构成回文字符串的要求就是左边和右边相等，所以字母的个数必须为偶数，所以把所有的字母个数统计出来，向下取偶数，由于最中间的字符可以任意，所以当统计到的长度小于数组的长度，就需要+1。

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int[] ints = new int[58];
        for (int i = 0; i < s.length(); i++) {
            ints[s.charAt(i)-'A']++;
        }
        int length = 0;
        //只有当字母的个数为偶数时才能构成回文串，所以把所有的字母的个数向下取偶数
        for (int num : ints) {
            length += (num / 2) * 2;
        }
        //当长度小于数组的长度时，因为最中间的字符可以任意取单个的，所以+1
        if (length < s.length()){
            length++;
        }
        return length;
    }
}
```