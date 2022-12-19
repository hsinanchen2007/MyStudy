>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 解法一：暴力破解法

时间复杂度是O(n ^ 3)，其中n为字符串s的长度。空间复杂度是O(1)。

执行用时：96ms，击败23.81%。消耗内存：35.9MB，击败99.43%。

```java
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n;
        if (s == null || (n = s.length()) == 0) {
            return 0;
        }
        int result = 1;
        boolean flag;
        //当i为n - result时，最长的字符串也仅仅是[n - result, n - 1]，其长度仅为result，不可能比result更大，故没必要继续判断
        for (int i = 0; i < n - result; i++) {
            for (int j = i + 1; j < n; j++) {
                //判断[i, j]内的字符串是否是不包含重复字符的字符串
                flag = true;   //默认[i, j]内的字符串是不包含重复字符的字符串
                for (int k = i; k < j; k++) {
                    //遍历[i, j)内的字符，如果存在和j处字符相等的字符，那么该子串就不满足条件
                    if (s.charAt(k) == s.charAt(j)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    result = Math.max(result, j - i + 1);   //如果[i, j]内的字符串不包含重复字符，那么更新result的值
                } else {
                    break;  //[i, j]已经存在重复字符了，继续增大j已经没有意义，考虑下一个起点i
                }
            }
        }
        return result;
    }
}
```
# 解法二：哈希表 + 滑动窗口

时间复杂度是O(n)，其中n为字符串s的长度。空间复杂度是O(1)。

执行用时：9ms，击败97.28%。消耗内存：36.5MB，击败97.26%。

```java
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n;
        if (null == s || (n = s.length()) == 0) {
            return 0;
        }
        boolean[] appear = new boolean[256];
        int left = 0, right = -1, result = 0; //滑动窗口范围是[left, right]
        while (right + 1 < n) {
            if (!appear[s.charAt(right + 1)]) {
                right++;
                appear[s.charAt(right)] = true;
            } else {
                appear[s.charAt(left)] = false; //因为滑动窗口中不可能包含重复字符，故去除left处的字符后，滑动窗口将不包含该字符
                left++;
            }
            result = Math.max(result, right - left + 1);
        }
        return result;
    }
}
```
# 解法三：解法二的改进

在解法二中，我们用一个boolean类型的数组appear记录某字符是否在滑动窗口[left, right]范围内出现过。

我们将这个boolean类型的数组改成int类型的数组，并用其记录某字符在滑动窗口[left, right]范围内最近出现的位置，这样，当我们移动left指针时就可以做一个小优化。

时间复杂度是O(n)，其中n为字符串s的长度。空间复杂度是O(1)。

执行用时：9ms，击败94.74%。消耗内存：39MB，击败84.02%。

```java
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] last = new int[256];  //记录某字符最近出现的索引
        Arrays.fill(last, -1);
        int left = 0, right = -1, result = 0;
        while (right + 1 < s.length()) {
            right++;
            if (last[s.charAt(right)] != -1) {  //如果说right处的字符重复了
                //将滑动窗口的左指针left指向重复字符的下一个位置，当然，left指针不能左移
                left = Math.max(left, last[s.charAt(right)] + 1);
            }
            result = Math.max(result, right - left + 1);
            last[s.charAt(right)] = right;
        }
        return result;
    }
}
```
# 解法四：动态规划

状态定义：

dp[x]:字符串s中以索引x处字符结尾的最长不含重复字符的子字符串长度。

状态转移：

（1）dp(0) = 1。

（2）如果第x个字符在之前未出现过，dp[x] = dp[x - 1] + 1。

（3）如果第x个字符在之前索引y处出现过，如果(x - y) <= dp[x - 1]，dp[x] = x - y。否则dp[x] = dp[x - 1] + 1。

时间复杂度是O(n)，其中n为字符串s的长度。空间复杂度是O(1)。

执行用时：9ms，击败94.74%。消耗内存：37.9MB，击败90.45%。

```java
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n;
        if (s == null || (n = s.length()) == 0) {
            return 0;
        }
        int[] last = new int[256];
        Arrays.fill(last, -1);
        int dp = 1, result = 1;
        last[s.charAt(0)] = 0;
        for (int i = 1; i < n; i++) {
            char c = s.charAt(i);
            if (last[c] == -1) {
                dp++;
            } else {
                if (i - last[c] <= dp) {
                    dp = i - last[c];
                } else {
                    dp++;
                }
            }
            last[c] = i;
            result = Math.max(result, dp);
        }
        return result;
    }
}
```