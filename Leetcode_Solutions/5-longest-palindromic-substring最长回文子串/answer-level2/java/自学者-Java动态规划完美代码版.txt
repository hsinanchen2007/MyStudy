### 解题思路
* 动态规划
* 方案一、初始化1个字母的回文，混合初始化1个以上的回文
* 方案二、初始化1个字母，初始化两个字母，剩下的跑3个以上字母的动态规划
* 
### 踩坑
* 很多个视频，很多种讲解，关键位置总是介绍的不清不楚
* 旁边认为动态规划不是最优解，都编写其他解的方案

【方案一、只初始化单个字母】 【方案二、初始化单个字母，两个字母，代码更加简洁】
```java [] 
// 方案一
class Solution {
    public String longestPalindrome(String s) {
       assert s != null && s.length() <= 1000;
        int len = s.length();
        if (s.isEmpty() || len == 1) {
            return s;
        }

        boolean[][] dp = new boolean[len][len];
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
        }

        //回文最大长度为1；
        int maxLen = 1;
        int start = 0;

        for (int size = 1; size < len; size++) {
            for (int left = 0; left < size; left++) {
                if (s.charAt(left) == s.charAt(size)) {
                    if(size - left < 3) {
                         dp[left][size] = true;
                    }else {
                         dp[left][size] =  dp[left + 1][size - 1];
                    }
                   
                } else {
                    dp[left][size] = false;
                }
                
                if (dp[left][size]) {
                    int curLen = size - left + 1;
                    if (curLen > maxLen) {
                        maxLen = curLen;
                        start = left;
                    }
                }
            }
        }
        return s.substring(start, start + maxLen);
    }         
}
```

```java []
// 方案二
class Solution {
    public String longestPalindrome(String s) {
       assert s != null && s.length() <= 1000;
        int len = s.length();
        if (s.isEmpty() || len == 1) {
            return s;
        }
                //回文最大长度为1；
        int maxLen = 1;
        int start = 0;

        boolean[][] dp = new boolean[len][len];
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
        }
        for (int i = 0; i < len - 1; i++) {
            if (s.charAt(i) == s.charAt(i+1)) {
                dp[i][i+1] = true;
                maxLen = 2;
                start = i;
            }
        }

        for (int size = 3; size <= len; size++) {
            for (int left = 0; left < len - size + 1; left++) {
                int right = left + size - 1;
                if (s.charAt(left) == s.charAt(right) && dp[left + 1][right - 1]) {
                   dp[left][right] = true;
                }
                
                if (dp[left][right]) {
                    int curLen = right - left + 1;
                    if (curLen > maxLen) {
                        maxLen = curLen;
                        start = left;
                    }
                }
            }
        }
        return s.substring(start, start + maxLen);
    }         
}
```