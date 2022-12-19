### 思路一：

因为该最长回文串，由我们自己拼接，所以，关键在于字母出现次数的奇偶，如果出现偶数次，一定可以构成回文；反之，奇数次的话，次数除以2，得到的就是该字母可组成回文的对数（比如，字母 a 出现了 7次，显然有6次可以构成回文，7/2 = 3，然后乘以2即可），最后如果有出现奇数次的字母，+1即可。

下面就是怎么存储了，哈希可以，但是考虑到只有大小写英文字母，故用长度为58的数组存储每个字母出现的次数。

### 代码：

时间复杂度O(n)，空间复杂度O(K)，其中 K 为字母个数

```java
class Solution {
    public int longestPalindrome(String s) {
        if (s == null || s.length() <= 0) {
            return 0;
        }
        int len = s.length(), maxLen = 0;
        boolean hasOdd = false;
        int [] arr = new int [58]; // 58 = 122 - 65 + 1
        for (int i = 0; i < len; i++) {
            char c = s.charAt(i);
            arr[c - 'A'] += 1;
        }
        for (int i = 0; i < 58; i++) {
            if (arr[i] % 2 == 0) {
                maxLen += arr[i];
            } else {
                hasOdd = true;
                maxLen += (2 * (arr[i] / 2));
            }
        }
        if (hasOdd) {
            maxLen += 1;
        }
        return maxLen;
    }
}
```

### Result：

Runtime：3ms

Your runtime beats 54.42% of java submissions.