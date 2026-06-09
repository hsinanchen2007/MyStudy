
#### 题解 1：

**递归 + 回溯**

> 在我们使用递归解决问题之前，必须注意两个重要的点，一个是递归函数，一个是边界条件，通常在确定了递归函数和边界条件之后，递归的问题基本就得到了解决

isMatch(String s, String p) 表示字符串 s 是否满足字符规律 p

- 递归边界

当p为null 的时候，判断 s.isEmpty()

- 递归函数

分为两个部分，一部分是当匹配串第二个元素不是 "*" 时候，此时递归函数为

**first && isMatch(s.substring(1), p.substring(1))**

当匹配串第二个元素是 "*" 的时候，此时分为直接匹配零个前面的元素 和 匹配多个前面的元素两种情况

**isMatch(s, p.substring(2)) || (first && isMatch(s.substring(1), p));**

    public boolean isMatch(String s, String p) {
        if(p.isEmpty()) return s.isEmpty();
        
        boolean first = !s.isEmpty() && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.');
        
        if(p.length() >= 2 && p.charAt(1) == '*'){
            return isMatch(s, p.substring(2)) || (first && isMatch(s.substring(1), p));
        }else{
            return first && isMatch(s.substring(1), p.substring(1));
        }
    }
#### 题解 2：

 **动态规划**

分析题解1，不难发现，其中有很多重复的步骤，关于这点，我们可以引入备忘录的方式进行优化，进而推导出动态规划的解决方案

当匹配串的第 j+1个元素为 "*" 的时候：dp[i] [j] = dp[i] [j+2] || (first && dp[i+1] [j])

否则：dp[i] [j] = first && dp[i+1] [j+1]

需要注意的是，我们最终得到的结果是判断dp[0] [0] 是否满足正则表达式匹配，所有我们需要从后往前遍历，并且初始化 dp[text.length()] [pattern.length()] = true

    public boolean isMatch(String text, String pattern) {
        boolean[][] dp = new boolean[text.length() + 1][pattern.length() + 1];
        dp[text.length()][pattern.length()] = true;
        
        //注意从text.length()开始，如果text为null，pattern为 a* 也满足条件
        for (int i = text.length(); i >= 0; i--){ 
            for (int j = pattern.length() - 1; j >= 0; j--){
                boolean first_match = (i < text.length() &&
                                       (pattern.charAt(j) == text.charAt(i) ||
                                        pattern.charAt(j) == '.'));
                if (j + 1 < pattern.length() && pattern.charAt(j+1) == '*'){
                    dp[i][j] = dp[i][j+2] || first_match && dp[i+1][j];
                } else {
                    dp[i][j] = first_match && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }


