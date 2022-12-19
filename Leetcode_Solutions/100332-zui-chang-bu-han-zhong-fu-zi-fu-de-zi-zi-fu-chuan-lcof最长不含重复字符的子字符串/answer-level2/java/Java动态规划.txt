### 解题思路
我们先介绍使用动态规划的思路来解决
  首先定义函数f(i)为以第i个字符为结尾的不包含重复字符的子字符串的最长长度.我们从左到右一次扫描字符串中的每一个字符.当我们计算以第i个字符为结尾的不包含重复字符的子字符串的最长长度f(i)时,我们已经知道了f(i-1))
 下面分几种情况:

  - 如果第i个字符在之前没有出现过,那么f(i) = f(i-1) + 1

  - 如果第i个字符在之前出现过,会出现两种情况,我们先计算下第i个字符和它上次出现在字符串中的位置的距离,计为d.
1. 第一种情形是d小于或者等于f(i-1),此时第i个字符上次出现在f(i-1)对应的最长子字符串之中,因此f(i) = d
2. 第二种情形是d大于f(i-1),此时第i个字符上次出现在f(i-1)对应的最长子字符串之前,因此有f(i) = f(i-1) + 1
时间复杂度O(n),空间复杂度O(n)

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.equals("")) return 0;
        int len = s.length();
        //dp(i)为以第i个字符为结尾的不包含重复字符的子字符串的最长长度
        int[] dp = new int[len];
        dp[0] = 1;
        for(int i = 1;i < len;i++){
            char cur = s.charAt(i);
            String subStr = s.substring(0,i);
            if(!subStr.contains(cur+"")){
                dp[i] = dp[i-1] + 1;
            }else{
                int d = subStr.length() - subStr.lastIndexOf(cur) ;//距离
                if(d <= dp[i -1]) dp[i] = d;
                else dp[i] = dp[i - 1] + 1;
            }
        }
        int max = 0;
        for(int i : dp){
            max = Math.max(max,i);
        }
        return max;
    }
}
```