### 解题思路
 
![u=1949534317,3087470638&fm=26&gp=0.jpg](https://pic.leetcode-cn.com/2d917e473ac9b00dbdbe0445d31e3d934741f744c904f861c702371b5ae883c9-u=1949534317,3087470638&fm=26&gp=0.jpg)

注意二个点：
1、缓存的边界，大小写字符串的返回，我为了无脑，直接265下去
2、返回的值是否小于字符串的长度，如果小于，那么就需要对结果 + 1

### 代码
基础版
```java
class Solution {
    public int longestPalindrome(String s) {
        int len = s.length();
        if (len == 0) return 0;
        int[] dp = new int[256];
        for (char ch : s.toCharArray()) {
            dp[ch]++;
        }
        int max = 0;
        for (int in : dp) {
            if (in >= 2) {
                max += in / 2 * 2;
            }
        }
        
        return max < len ? max + 1: max;
    } 
}
```

改造一次，（有兴趣的继续改造把，算法无止境，追求各不同）
```java
class Solution {
    public int longestPalindrome(String s) { 
        int[] dp = new int[256]; 
        int result = 0 ;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            dp[ch]++;
            if (dp[ch] == 2) {
                dp[ch] = 0;
                result += 2;
            }
        } 
        return result < s.length() ? result + 1: result;
    } 
}
```
