**题意分析**
(1) 排列 n 对括号，生成所有可能的有效括号字符串（结果为卡特兰数数列）。
(2) 可以先将 n 对括弧自由组合排列，再选出其中的有效括号字符串。
*** 需要注意的是排除重复的有效括号组合和减少错误组合的遍历。

有效括号字符串：
所有单括号都能找到对应的另一半组成有效括号"()"，使得所有括弧两两配对。
卡特兰数（Catalan number）：
前几项为 1、1、2、5、14... ，当 n >= 2 符合递推公式 
f(n) = f(0) * f(n-1) + f(1) * f(n-2) + ... + f(n-2) * f(1) + f(n-1) * f(0) 的数列，
推导公式为 f(n) = C(2n,n)/(n+1) = (2n!)/(n!*(n+1)) (n=0,1,2,...)。

**方法一：深度优先搜索（DFS）**
思路：
(1) 从头开始递归拼接可能的组合字符串。
(2) 过程中删除不符合条件的组合和记录括弧拼接完后的组合。
```
public class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        if (n == 0) {
            return ans;
        }
        // 执行深度优先遍历，搜索可能的结果。
        dfs("", n, n, ans);
        return ans;
    }

    private void dfs(String curStr, int left, int right, List<String> ans) {
        // 如果剩余的 "(" 数大于剩余的 ")" ，则一定有已拼接 ")" 找不到对应的 "(" 。
        if (left > right) {
            return;
        }
        // 得到符合要求的排列。
        if (left == 0 && right == 0) {
            ans.add(curStr);
            return;
        }
        // 递归拼接左右括弧。
        if (left > 0) {
            dfs(curStr + "(", left - 1, right, ans);
        }
        if (right > 0) {
            dfs(curStr + ")", left, right - 1, ans);
        }
    }
}
```
