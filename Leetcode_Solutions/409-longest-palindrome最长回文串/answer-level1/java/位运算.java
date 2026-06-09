### 解题思路
128位 ascii 码，最后记录出现奇数次的数字个数。

### 缺陷
从字母 a 到字母 Z 应该不需要 128位，可以改进，不过我懒。

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        if (s == null) return 0;
        int len = s.length();
        if (len <= 1) return len;

        long low64 = 0L;
        long high64 = 0L;
        for (char c : s.toCharArray()){
            if (c >= 64){
                high64 ^= 1L << (c - 64);
            } else{
                low64 ^= 1L << c;
            }
        }
        int odd = Long.bitCount(high64) + Long.bitCount(low64);
        return odd > 1 ? len - odd + 1 : len;
    }
}
```