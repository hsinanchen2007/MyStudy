### 解题思路
1. 和最大矩形一样，利用了柱状图中最大矩形的思路，使用stack的方法为基础，计算结果。
2. 和最大矩形不同的是，计算面积是，不是长乘宽，而是长宽较小的那个的平方。
3. 结果时间复杂度较高。

1. 第二种解决方案是动态规划的方法，经过分析可以得知，以当前点为右下角的正方形可以根据上，左，左上的状态确定。本题使用2维int数组保存中间变量。申请的长度为列数加1，这样的好处是将第一行和第一列非特殊化，简化代码。

### 代码

```java
class Solution {
    public int maximalSquare(char[][] matrix) {
        if(matrix == null || matrix.length == 0 || matrix[0].length == 0) return 0;
        int[] row = new int[matrix[0].length];
        int res = 0;
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                if(matrix[i][j] == '1') row[j] += 1;
                else row[j] = 0;
            }
            res = Math.max(res, helper(row));
        }
        return res;
    }

    public int helper(int[] nums){
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);
        int res = 0, curArea = 0;
        for(int i = 0; i < nums.length; i++){
            while(stack.peek() != -1 && nums[i] <= nums[stack.peek()]){
                int t = stack.pop();
                int len = i - stack.peek() - 1;
                res = Math.max(res, nums[t] > len ? len * len : nums[t] * nums[t]);
            }
            stack.push(i);
        }
        while(stack.peek() != -1){
            int t = stack.pop();
            int len = nums.length - stack.peek() - 1;
            res = Math.max(res, nums[t] > len ? len * len : nums[t] * nums[t]);
        }
        return res;

    }
}

class Solution {
    public int maximalSquare(char[][] matrix) {
        if(matrix == null || matrix.length == 0 || matrix[0].length == 0) return 0;
        int length = 0;
        int[][] dp = new int[2][matrix[0].length+1];
        for(int i = 1; i <= matrix.length; i++){
            for(int j = 1; j <= matrix[0].length; j++){
                if(matrix[i-1][j-1] == '1')
                    dp[i%2][j] = Math.min(Math.min(dp[(i-1)%2][j], dp[(i-1)%2][j-1]), dp[i%2][j-1]) + 1;
                else dp[i%2][j] = 0;
                length = Math.max(dp[i%2][j], length);
            }
        }
        return length*length;
    }
}
```