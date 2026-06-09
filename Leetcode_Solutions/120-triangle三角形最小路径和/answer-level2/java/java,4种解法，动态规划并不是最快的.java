### 解题思路
 思路1，暴力解法，直接使用递归，根据树的定义，只要min(left, right) + current，时间复杂度 O(2log n),空间 O(n^2)
 思路2，记忆法，保持计算过的节点， 速度最快,时间复杂度 O(log n),空间 O(n^2)
 思路3，动态规划  时间复杂度 O(n^2),空间 O(n^2)
 思路4， 动态规划，空间优化， 时间复杂度 O(n^2),空间 O(n)
### 代码

```java
class Solution {
     /**
     * 思路4， 对思路3， 进行分析，发现只使用下一层数据，之前的数据不再使用
     * 所以我们只用存储一层最新的数据就可以了，把空间复杂度降到O(n)
     * 由于 dp[i] = min(dp[i], dp[i+1]),所以每次dp[i]更新数据之后
     * 不会对 dp【i+1]的计算造成影响。
      * @param triangle
     * @return
     */
    public int minimumTotal(List<List<Integer>> triangle) {
        if (null == triangle || triangle.size() == 0)
            return 0;
        int len = triangle.size();
        int[] dp = new int[len+1];
        //从最后一层开始
        for (int level = len - 1; level >= 0; level--)
            for (int start = 0; start < triangle.get(level).size(); start++)
                dp[start] = triangle.get(level).get(start) + Math.min(dp[start], dp[start+1]);
        return  dp[0];
    }
    /**
     * 思路3，
     * 自底向上，动态规划的思想
     * 通过思路1，2，我们知道一个节点值，由于下一层孩子节点的最小值决定
     * 即 dp[i][j] = dp[i][j] + min(dp[i+1,j], dp[i+1,j+1]
     * 那这个就是我们的递推式，因为上层由下一层决定，我们初始从
     * 最后一层开始，由于最后一层的left，right肯定是0，所以申请层数多一层,作为辅助计算最后一层
     * 最终我们只取出，dp[0][0],即最后的结果
     * 时间复杂度是 O(n^2)
     * 空间复杂度 （ O(n^2) ,不符合题目加分项
     * @param triangle
     * @return
     */
    public int minimumTotal3(List<List<Integer>> triangle) {
        if (null == triangle || triangle.size() == 0)
            return 0;
        int len = triangle.size();
        int[][] dp = new int[len+1][len+1];
        //从最后一层开始
        for (int level = len - 1; level >= 0; level--)
            for (int start = 0; start < triangle.get(level).size(); start++)
                dp[level][start] = triangle.get(level).get(start) + Math.min(dp[level + 1][start], dp[level+1][start+1]);
        return  dp[0][0];
    }
    private List<List<Integer>> triagnle;
    private int[][] mem;
    /**
     * 思路2 , 存储计算过的节点，避免重复计算
     * 时间复杂度O（2^(n-1) -1)= O(log (n-1)) ,因为每个节点计算一次，最后一层不计算，应该是小于O(n)
     * 空间复杂度 O(n^2 + n(n+1)/2) = O(n ^ 2),辅助计算空间。
     * @param triangle
     * @return
     */
    public int minimumTotal2(List<List<Integer>> triangle) {
        if (null == triangle || triangle.size() == 0)
            return 0;
        this.triagnle = triangle;
        this.mem = new int[triangle.size()][triangle.size()] ;
        return  getMin(0, 0);
    }
    private int getMinMem(int level, int start){
        if (level == this.triagnle.size() - 1)
            return this.triagnle.get(level).get(start);
        if (mem[level][start] != 0)
            return mem[level][start];
        int left = getMinMem(level + 1, start);
        int right = getMinMem(level + 1, start + 1);
        return mem[level][start] = Math.min(left, right) + this.triagnle.get(level).get(start);
    }
    /**
     * 思路1，
     * 时间复杂度 是所有的节点的left right,但是中间节点会被计算两次，所以是 O(n^2)
     * 空间复杂度 O(n)， 使用辅助计算空间；
     * @param triangle
     * @return
     */
    public int minimumTotal1(List<List<Integer>> triangle) {
        if (null == triangle || triangle.size() == 0)
            return 0;
       this.triagnle = triangle;
       return  getMin(0, 0);
    }
    private int getMin(int level, int start) {
       if (level == this.triagnle.size() - 1)
           return this.triagnle.get(level).get(start);
       int left = getMin(level + 1, start );
       int right = getMin(level + 1, start + 1);
       return  Math.min(left, right) + this.triagnle.get(level).get(start);
    }
}
```