### 解题思路
记录每个字母出现的次数于哈希表中，哈希表用长度为52的int[]数组即可（大小写共52个字母）。
首先统计所有出现次数为偶数的字母的总个数；
其次，对于所有出现次数为奇数且大于2的字母，将它们各自的出现次数减一后相加（减一是因为回文串需要偶数个字母）；
至此，得到的所有字母都是成对出现的，个数均为偶数；
最后，若还有多余的字母，再加一个，放到回文串中央，可构成最长回文串。

时间复杂度：O(n)。
空间复杂度：O(n)。哈希表大小是常数，为52，但是辅助的字符数组大小char[]与字符串s的长度相关。

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int[] hash = new int[52];
        char[] letter = s.toCharArray();
        int len = letter.length;
        int ans = 0;
        for(int i = 0; i < len; i++)
        {
            char c = letter[i];
            if(c <= 'Z' && c >= 'A')    hash[c - 'A']++;
            if(c <= 'z' && c >= 'a')    hash[c - 'a' + 26]++;
        }
        for(int i = 0; i < 52; i++)
        {
            if(hash[i] % 2 == 0)    ans += hash[i];
            else if(hash[i] > 2)    ans += hash[i] - 1;
        }
        if(ans < len)   ans += 1;
        return ans;
    }
}
```