这道题花费了我一上午的时间。

首先要明确的一点：这种存在最优子结构的问题，一定可以使用动态规划。

有了大方向，问题就转化为如何确定最优子结构，以及如何利用最优子结构来推导当前的最优解。

设置一个矩阵，矩阵元素为三元组 {row, line, area}.
1. row 为当前位置从该点向左走，元素 '1' 的长度。若为 '0' 或到达边界 则终止。
2. line 为当前位置从该点向上走，元素 '1' 的长度，若为 '0' 或到达边界 则终止。
3. area 为当前位置能构造的矩阵面积的最大值。

遍历矩阵，首先对于第一行/第一列上的元素进行动态规划，若元素值为 0, 则三元组为 {0,0,0}, 若元素为 1, 则行三元组为{dp[i][j-1][0] + 1, 1, dp[i][j-1][2] + 1}, 列上的三元组为{dp[i-1][j][0] + 1, 1, dp[i-1][j][2] + 1}.

对于下标 i!=0, j != 0 的元素，dp[i][j][0] = dp[i][j-1][0] + 1, dp[i][j][1] = dp[i - 1][j][1] + 1.

最关键的为求 dp[i][j][2] 部分（即 area 部分），可见图例：

图例：
假设给定下列矩阵，求最大矩形面积：
![在这里插入图片描述](https://pic.leetcode-cn.com/cd905c7c2df8a740529110157211455e63712f6002be19c42982f1d64f97c480.png)

首先初始化第一行、第一列：
![在这里插入图片描述](https://pic.leetcode-cn.com/fdbe3dfcbdd817fc2d376ecae41885bf86dc5da4068c5e1405c82b5ae4cb374e.png)

开始遍历其他位置上元素：
![在这里插入图片描述](https://pic.leetcode-cn.com/191d3b58246c3957d1a5493243fa606e548776e9ee4300541557a539569d117d.png)
对于 '?' 处，即 dp[1][1][2]（即 area 的值），如何求解？

可以看出，dp[1][1] 处, row = 2, line = 1, 即从该点向左数，一共有 2 个值为 '1' 的元素，从该点向上数， 一共有 1 个值为 '1' 的元素（因此不需要向上求矩阵面积，只有一行）。此时，area 的值 为 2 * 1 = 2.

![在这里插入图片描述](https://pic.leetcode-cn.com/13a722a345b334e7e6b84206da7c002c5b1f6dacce3b21848137e42c2d19f925.png)
继续向后遍历，到达 dp[1][2] 位置，此时 row = 3, line = 2, 我们需要比较 2 个情况，即需要比较下图中被蓝色、红色框起来的面积哪个更大一点。
![在这里插入图片描述](https://pic.leetcode-cn.com/0c83245344ddda52bc369e6ac0f7e476ea5e3394c6e0caad05c65341e5cc37f3.png)

此时，还有一点不太清楚：框的大小如何选取？答：需要依照 line 所涉及到的行，对于每一行中，一定有一个 row', 若 row' < row, 则将 row = row'.

 ![在这里插入图片描述](https://pic.leetcode-cn.com/8ca4694c758d377ebda4525204ca9af4c21ada57237945426a93b134c8e54a96.png)
例如，对于 dp[2][2]， 需要向上比较 line = 3 行，分别能向左触及 2, 2, 1 个格子。但由于高度不同，因此 area 会出现差异。

![在这里插入图片描述](https://pic.leetcode-cn.com/25472545df109b55e51d8e8304c3571902463bf200fb03c4bc98b7b3ab38a0fb.png)
以上为整个动态规划过程。

代码：
```cpp
class Solution {
public:
    void update( vector< vector< vector<int>>>& record, int begin_i, int begin_j){
        int line_min = record[begin_i][begin_j][0];
        int row = record[begin_i][begin_j][1];
        
        for( int count = 0; count < row; count++){
            line_min = min( line_min, record[ begin_i-count][begin_j][0]);
            record[begin_i][begin_j][2] = max( record[begin_i][begin_j][2], line_min * (count + 1));
        }
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if( !matrix.size())
            return 0;
        //辅助矩阵，里面寸了三个值：当前行/列的长度、当前可达到的最大额矩阵面积
        vector< vector< vector<int>>> record( matrix.size(), vector<vector<int>>( matrix[0].size(), {0,0,0}));
        int res = 0;
        //dp 过程
        for( int i = 0; i < matrix.size(); i++)
            for( int j = 0; j < matrix[0].size(); j++){
                if( matrix[i][j] == '0')
                    ;
                else
                    if( i == 0 && j == 0)
                        record[i][j] = { 1, 1, 1};                
                    else if( i == 0)
                        record[i][j] = {record[i][j-1][0] + 1, 1, record[i][j-1][2] + 1};
                    else if( j == 0)
                        record[i][j] = {1, record[i-1][j][1] + 1, record[i-1][j][2] + 1};
                    else{
                        record[i][j][0] = record[i][j-1][0] + 1, record[i][j][1] = record[i-1][j][1] + 1;
                        update( record, i, j);
                    }
                res = max( res, record[i][j][2]);
            }
            
        return res;
    }
};
```
