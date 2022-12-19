### 解题思路
定义：旗帜，就是bbacc中的a
统计共有多少个字母出现了奇数次，得到count
用字符串长度减去count，多少个字母出现了偶数次，即旗帜两边的个数evenCount
再加上1（即旗帜的长度），得到最终答案

### 代码

```java
class Solution {
     public int longestPalindrome(String s) {
        // 找出可以构成最长回文串的长度
        int[] arr = new int[128];
        for(char c : s.toCharArray()) {
            arr[c]++;
        }
        int count = 0;
        for (int i : arr) {
            count += (i % 2);
        }
        return count == 0 ? s.length() : (s.length() - count + 1);
    }
}
```