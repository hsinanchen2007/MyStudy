动态规划
    将每一行的头部对齐后再观察：
    如果从上向下推，对该行的每一个元素都要考虑它的正上方和它的左上角，所以对于头部和尾部要做边界处理
    如果从下往上推，对该行的每一个元素都要考虑它的正下方和它的右下角，对于头部和尾部不用特殊处理
    综上，选择从下向上推
    执行用时 :3 ms, 在所有 Java 提交中击败了97.94%的用户
```
class Solution {
    public int minimumTotal(List<List<Integer>> t) {
        int rows = t.size();
        int[] dp = new int[rows];
        
        List<Integer> tail = t.get(rows - 1);//最后一行
        for(int i = 0; i < rows; i++) {
            dp[i] = tail.get(i);
        }
        
        //从倒数第二行开始
        for(int i = rows - 1; i > 0; i--) {//第row行有rows列，比如第3行有3列
            List<Integer> cur = t.get(i - 1);
            for(int j = 0; j < i; j++) {
                dp[j] = Math.min(dp[j],dp[j + 1]) + cur.get(j);
            }
        }
        return dp[0];
        
    }
}
```
