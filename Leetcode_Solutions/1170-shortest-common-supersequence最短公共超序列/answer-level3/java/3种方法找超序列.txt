### 解题思路
方法一  记忆化深度搜索。  最后一个case超时
方法二  动态规划找最短超序列，dp[i][j] 表示 str1 前i个 与 str2前j个组成的超序列 . 最后一个case超时 。优化使用滚动数组还是超时
方法三  动态规划找最长公共序列，然后进行归并组成超序列。  勉强通过

### 代码
方法一
```
    HashMap<String, String> dsMap;
    // 深度搜索
    public String shortestCommonSupersequence2(String str1, String str2) {
        if (str1 == null || str2 == null) {
            return null;
        }
        if (str1.equals("")) {
            return str2;
        }
        if (str2.equals("")) {
            return str1;
        }
        dsMap = new HashMap<>();
        return ds(str1, str2);
    }

    public String ds(String str1, String str2) {
        if (dsMap.get(str1 + ' ' + str2) != null) {
            return dsMap.get(str1 + ' ' + str2);
        }
        if (str1 == null || str2 == null) {
            return "";
        }
        if (str1.equals("")) {
            return str2;
        }
        if (str2.equals("")) {
            return str1;
        }
        int i = str1.length() - 1;
        int j = str2.length() - 1;
        if (str1.charAt(i) == str2.charAt(j)) {

            String ret = ds(str1.substring(0, i), str2.substring(0, j)) + str1.charAt(i);
            dsMap.put(str1 + ' ' + str2, ret);
            return ret;
        } else {
            String pre = ds(str1.substring(0, i), str2.substring(0, j)) + str1.charAt(i) + str2.charAt(j);

            String t1 = null;
            for (int k = i - 1; k >= 0; k--) {
                if (str1.charAt(k) == str2.charAt(j)) {
                    t1 = ds(str1.substring(0, k), str2.substring(0, j)) + str1.substring(k);
                    break;
                }
            }
            String t2 = null;
            for (int k = j - 1; k >= 0; k--) {
                if (str2.charAt(k) == str1.charAt(i)) {
                    t2 = ds(str1.substring(0, i), str2.substring(0, k)) + str2.substring(k);
                    break;
                }
            }

            if (t1 == null && t2 == null) {
                dsMap.put(str1 + ' ' + str2, pre);
                return pre;
            } else if (t1 == null) {
                String min = pre.length() < t2.length() ? pre : t2;
                dsMap.put(str1 + ' ' + str2, min);
                return min;
            } else if (t2 == null) {
                String min = pre.length() < t1.length() ? pre : t1;
                dsMap.put(str1 + ' ' + str2, min);
                return min;
            } else {
                String min = t1.length() < t2.length() ? t1 : t2;
                min = pre.length() < min.length() ? pre : min;
                dsMap.put(str1 + ' ' + str2, min);
                return min;
            }
        }
    }

```

方法二
```
 public String shortestCommonSupersequence1(String str1, String str2) {
        if (str1 == null || str2 == null) {
            return null;
        }
        int n = str1.length();
        int m = str2.length();
        String[] dp = new String[m + 1];
        String[] tmp = new String[m + 1];   // 临时数组用来滚动
        // 不好理解的话 可以先用 dp[n][m] 二维数组来表示
        tmp[0] = "";
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0) {
                    dp[j] = str2.substring(0, j);
                } else if (j == 0) {
                    dp[j] = str1.substring(0, i);
                } else {
                    if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                        dp[j] = tmp[j - 1] + str1.charAt(i - 1);
                    } else {
                        String min;
                        if (tmp[j].length() < dp[j - 1].length()) {
                            min = tmp[j] + str1.charAt(i - 1);
                        } else {
                            min = dp[j - 1] + str2.charAt(j - 1);
                        }
                        if (tmp[j - 1].length() + 1 < min.length()) {
                            min = tmp[j - 1] + str1.charAt(i - 1) + str2.charAt(j - 1);
                        }
                        dp[j] = min;
                    }
                }
            }
            tmp = dp;
            dp = new String[m + 1];
        }
        return tmp[m];
    }

```

方法三
```java
class Solution {
   public String shortestCommonSupersequence(String str1, String str2) {
        if (str1 == null || str2 == null) {
            return null;
        }
        int n = str1.length();
        int m = str2.length();
        String[][] dp = new String[n + 1][m + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++)
                dp[i][j] = "";
        }
        // dp 找最长公共子序列
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1] + str1.charAt(i - 1);
                else
                    dp[i][j] = (dp[i - 1][j].length() > dp[i][j - 1].length() ? dp[i - 1][j] : dp[i][j - 1]);
            }
    
        String lcs = dp[n][m];
        StringBuilder ret = new StringBuilder();
        int i = 0, j = 0;
        // 开始进行归并
        for (int k = 0; k < lcs.length(); k++) {
            // 先将 str1 和 str2 都归并到第k个公共字符
            char ch = lcs.charAt(k);
            while (i < n && str1.charAt(i) != ch)
                ret.append(str1.charAt(i++));
            while (j < m && str2.charAt(j) != ch)
                ret.append(str2.charAt(j++));

            // 加公共字符
            ret.append(ch);
            ++i;
            ++j;
        }

        //加上每个字符串在LCS之后的字符
        return ret.append(str1.substring(i) + str2.substring(j)).toString();
    }
}
```