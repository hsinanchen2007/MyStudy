![题解.png](https://pic.leetcode-cn.com/7aecad6b071d219c736b82a3ee859b5965e5f6f92b226d400ca41660ced5ed34-%E9%A2%98%E8%A7%A3.png)
### 事先声明：
代码来自[@haiyuel](/u/haiyuel/)，写下我对大佬代码的理解，仅供学渣参考，大家一起学习。
### 准备工作
###### 题目描述：任意输入word，使用两指输入，计算手指的最短移动距离。
###### 等价问题：计算以最后一个字符为终点的手指移动距离最小值
###### 已知条件：输入word[0~length-1]、字符距离计算公式：|x1-x2|+|y1-y2|

### 解题思路
- #### 问题拆解
    输入word[0~length-1],以字符word[length-1]为结束字符的最小值可由word[length-2]的最小值求得：
    - 0~length-2的字符输入完成时，有两种情况：
（1）始终使用一指输入;
（2）最终一指停在位置length-2，一指停在0~length-2之间（左闭右开）。

    - 此时输入字符word[length-1]，有四种可选方式：
  若之前始终一指，
（1）依旧使用一指输入;
（2）换用另一根手指输入。
若之前使用的两指，
（3）选用位于length-2的手指进行输入;
（4）选用另一根手指输入。

- #### 状态定义
    dp[i][j]:以下标i的字符为结束字符的最小移动距离，一指停留在位置i，一指停留在位置j，其中i>=j，
    特别的，dp[i][i]表示始终使用一指输入的情况。

- #### 转移方程 
    由前两步可以推出四个状态转移方程，依次对应问题拆解中的四种方式的一种：
    - dp[i][i] = dp[i-1][i-1] + distance(i-1,i)
    - dp[i][i-1] = dp[i-1][i-1] + 0
    - dp[i][j] = dp[i-1][j] + distance(i-1,i)
    - dp[i][i-1] = dp[i-1][j] + distance(j,i)

- #### 代码实现
```
class Solution {
    public int minimumDistance(String word) {
        int len = word.length();
        char[] chars = word.toCharArray();  
        
        int[][] dp = new int[len][len];      // DP Array，
        int[][] dist = new int[26][26];   // distance[i][j]，存储字符之间的距离
                                            
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                dist[i][j] = distance(i,j);
        
        for (int i = 1; i < len; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);   // 初始化
            
            // 如果此前仅使用了一根手指，依旧仅使用一根手指
            dp[i][i] = dp[i-1][i-1] + dist[chars[i-1]-'A'][chars[i]-'A'];   
            // 或者将第二根手指放在第 i 个字母上，不产生移动距离；可以理解为 `d[i-1][i-1] + 0`
            dp[i][i-1] = Math.min(dp[i][i-1], dp[i-1][i-1]);

            //如果之前使用的两根手指，一指停留在i-1，一指停留在j
            for (int j = 0; j < i-1; j++) {
                // 将原先放在第 i-1 个字母上的手指移到 i 上，此时两根手指分别以第 i, j 个字母为终点 
                dp[i][j] = Math.min(dp[i][j], dp[i-1][j] + dist[chars[i-1]-'A'][chars[i]-'A']);      
                // 将原先放在第 j 个字母上的手指移到 i 上，此时两根手指分别以第 i, i-1 个字母为终点 
                dp[i][i-1] = Math.min(dp[i][i-1], dp[i-1][j] + dist[chars[j]-'A'][chars[i]-'A']);    
            }
 
        }
    
        int ret = Integer.MAX_VALUE;
        for (int i = 0; i < len-1; i++)
            ret = Math.min(ret, dp[len-1][i]);   // 无需考虑 dp[len-1][len-1]（代表始终一指输入），必然不是最优：在任意字符位置，选择另一指输入都会减少一次移动手指的距离。
            
        return ret;
    }
    
    private int distance(int a, int b) {
        int x1 = a / 6, y1 = a - 6*x1;
        int x2 = b / 6, y2 = b - 6*x2;

        return Math.abs(x2-x1) + Math.abs(y2-y1);
    }
    
    
}


```
### 性能分析
- 时间复杂度：O(n^2)
- 空间复杂度：O(n^2)

