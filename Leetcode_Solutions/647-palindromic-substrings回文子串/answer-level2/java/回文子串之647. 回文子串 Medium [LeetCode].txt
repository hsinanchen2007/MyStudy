[LeetCode笔记-Java版-专题篇](https://note.youdao.com/ynoteshare1/index.html?id=e3152a4cf9f16867c36adce45bc134cb&type=note)

`如果觉得写得有帮助的话希望可以给点个赞或是评论，有反馈写的才感觉有动力，有什么错误希望也能够指正。`


# 回文子串之647. 回文子串 Medium [LeetCode]
## 方法1：DP

```java

public int countSubstrings(String s) {
    if (s == null || s.length() == 0) {
        return 0;
    }
    int result = 0;
    boolean[][] dp = buildDPForCountSubstrings(s);
    for (int j = 0; j < dp.length; j++) {
        for (int i = 0; i <= j; i++) {
            if (dp[i][j]) {
                result++;
            }
        }
    }
    return result;
}


private boolean[][] buildDPForCountSubstrings(String s) {
    int n = s.length();
    boolean[][] dp = new boolean[n][n];
    //注意i 和j 的边界，只计算上半部分，j - i <= 1是为了处理边界，dp[i + 1][j - 1]是dp[i][j]砍头去尾后的是否是回文
    for (int j = 0; j < n; j++) {
        for (int i = 0; i <= j; i++) {
            if (i == j) {
                dp[i][j] = true;
            } else {
                dp[i][j] = s.charAt(i) == s.charAt(j) && (j - i <= 1 || dp[i + 1][j - 1]);
            }
        }
    }
    return dp;
}
```



## 方法2：中心扩展法
此法运行速度快
```java
/**
 * @param s
 * @return
 */
public int countSubstrings2nd(String s) {
    int result = 0;
    for (int i = 0; i < s.length(); i++) {
        //以当前点i位置，向两边扩展,以i i+1位置向两边扩展
        result += countSegment(s, i, i);
        result += countSegment(s, i, i + 1);
    }
    return result;
}


public int countSegment(String s, int start, int end) {
    int count = 0;
    //start往左边跑，end往右边跑，注意边界
    while (start >= 0 && end < s.length() && s.charAt(start--) == s.charAt(end++)) {
        count++;
    }
    return count;
}
```


