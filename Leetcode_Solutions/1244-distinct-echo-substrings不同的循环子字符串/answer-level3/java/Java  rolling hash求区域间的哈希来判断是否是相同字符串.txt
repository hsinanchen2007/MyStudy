```java
class Solution {
    public int distinctEchoSubstrings(String text) {
        long a = 29;
        long mod = (long)Math.pow(2, 63) - 1;
        int n = text.length();
        long[] hash = new long[n + 1];
        long[] pow = new long[n + 1];
        pow[0] = 1;
        for (int i = 1; i <= n; i ++) {
            hash[i] = (hash[i - 1] * a + text.charAt(i -1 )) % mod;
            pow[i] = (pow[i - 1] * a) % mod; 
        }
        HashSet<Long> hs = new HashSet<>();
        for (int i = 0; i < n; i ++) {
            for (int len = 2; i + len <= n; len += 2) {
                int mid = i + len / 2;
                long hash1 = (hash[mid] - hash[i] * pow[len / 2] + mod ) % mod;
                long hash2 = (hash[i + len] - hash[mid] * pow[len / 2] + mod ) % mod;
                if (hash1 == hash2) hs.add(hash1);
            }
        }
        return hs.size();
    }
}
```