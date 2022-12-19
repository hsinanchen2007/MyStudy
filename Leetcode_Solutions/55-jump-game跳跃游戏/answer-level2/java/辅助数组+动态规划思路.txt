### 解题思路
1，辅助数组保存当前索引值与相应值的和，即当前索引值能到达的最远长度
2，设置一维dp数组，i表示当前的索引值是否能到达最后的值

倒序遍历辅助索引数组，填充能到达的dp数组 返回dp[0]即可

两次遍历数组 时间复杂度 O(n) 
使用两个数组 空间复杂度 O(n)

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        //动态规划 dp
        if (nums.length <= 1) {
            return true;
        }

        //辅助数组 每个节点值 存当前能到达的最大索引号
        int len  = nums.length;
        int[] dp = new int[len-1];//只需存前n个数即可

        boolean[] dp1 = new boolean[len-1];//真正的dp数组

        //循环遍历数组 序号 + 索引号
        for (int i = 0; i < nums.length - 1; i++) {
            dp[i] = i + nums[i];//能到达的最大索引号
        }

        //右->左遍历 找出能到达的第一个数
        int i = len-2;
        int topIndex = i+1;
        while (i >= 0) {
            if (dp[i] >= topIndex) {//找到第一个数
                topIndex = i; 
                dp1[i] = true;
            }
            i--;    
        }

        return dp1[0];
    }
}
```