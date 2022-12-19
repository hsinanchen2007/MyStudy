### 解题思路
这个题也是属于最优子结构问题，一般是可以用动态规划解决的。
步骤：
1.求包含第i个字符的最长无重复子串，可以转化为求包含i-1个字符的无重复子串。
2.状态转移方程：DP[i],i记录遍历到第几个字符串来了，起始值为1.DP[i]的值记录了第i个无重复子串的起始位置。则在第i个字符的无重复子串的值就为i-DP[i]。这个DP方程可能有点奇怪，但是空间复杂度为O(n),只需要遍历一次。效率比较高。
状态转移方程有两种情况：
    1）如果第i个字符不在上一个无重复子串里面，则同样将起始位置赋值给当前dp
    2）如果第i个字符在上一个无重复子串里面，就将重复的子串的下一位赋值给当前dp。不可能有两个重复字符，因为上一个也是无重复子串。
具体实现看代码

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        //边界情况
        int length = s.length();
        if (length < 2) {
            return length;
        }
        int result = 1;
        //记录最长无重复字串的起始位置
        int[] dp = new int[length + 1];
        for (int i = 1; i <= length; i++) {
            dp[i] = i - 1;
        }
        for (int i = 2; i <= length; i++) {
            //当前要判断的字符
            String currentChar = String.valueOf(s.charAt(i - 1));
            //前一个最长无重复子串
            String sub = s.substring(dp[i - 1], i - 1);
            //如果前一个子串不包含当前字符，就将起始位置赋值给当前位置
            if (!sub.contains(currentChar)) {
                dp[i] = dp[i - 1];
            } else {
                //如果包含的话，就将起始位置设置为重复字符的下一个
                dp[i] = dp[i - 1] + sub.indexOf(currentChar) + 1;
            }
            result = Math.max(result, i - dp[i]);
        }
        return result;
    }
}
```