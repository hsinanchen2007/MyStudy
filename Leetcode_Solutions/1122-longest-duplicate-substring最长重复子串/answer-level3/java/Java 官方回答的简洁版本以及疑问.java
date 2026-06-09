### 解题思路

思路基本上是按照官方来的，简化了函数参数

疑问： mod 取不同值，得到的结果不一样
```java
 mod = (long)Math.pow(2, 32); 是对的
 mod = (long)Math.pow(2, 32) - 1; 是错的
```
有大神解答一下吗



### 代码

```java
class Solution {
    long mod = (long)Math.pow(2, 37) - 1;
    long a = 26;
    int nums[];
    int n;
    public String longestDupSubstring(String S) {
        nums = new int [S.length()];
        for (int i = 0; i < S.length(); i ++) {
            nums[i] = S.charAt(i) - 'a';
        }
        this.n = S.length();
        int left = 1;
        int right = n;
        while (left != right) {
            int mid = left + (right - left) / 2;
            if (search(mid) != -1) left = mid + 1;
            else right = mid;
        }
        int begin = search(left - 1);
        if (begin != -1) return S.substring(begin, begin + left - 1);
        return "";
    }

    public int search(int length) {
        long cur = 0;
        for (int i = 0; i < length; i ++) {
            cur = (cur * a + nums[i]) % mod;
        }
        long aL = 1;
        for (int i = 0; i < length; i++) {
            aL = (aL * a ) % mod;
        }
        HashSet<Long> hs = new HashSet<>();
        hs.add(cur);

        for (int i = 1; i <= n - length; i ++) {
            cur = (cur * a - aL * nums[i - 1] % mod + mod) % mod;
            cur = (cur + nums[i + length - 1]) % mod;
            if (hs.contains(cur)) return i;
            hs.add(cur);
        }
        return -1;
    }
}
```