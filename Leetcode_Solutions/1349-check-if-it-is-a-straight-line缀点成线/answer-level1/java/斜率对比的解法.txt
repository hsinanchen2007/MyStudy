1. 关于复杂度
  1.1 时间复杂度为O(n)
  1.2 空间负责度为O(1)
2. 我的解题思路
  2.1 根据第一以及第二个点计算初始斜率
  2.2 计算剩下的点以及第一个点的斜率，并与2.1的初始斜率对比
3. 提交记录
  3.1 力扣中耗时0ms,消耗38.3MB内存
  3.2 leetcode中耗时0ms,消耗42MB内存
4. Q&A

```
/**
 * Problem
 *     1232.Check If It Is a Straight Line
 *     https://leetcode.com/problems/check-if-it-is-a-straight-line/
 *     https://leetcode-cn.com/problems/check-if-it-is-a-straight-line/
 * Grade of difficulty
 *     Easy
 * Related topics
 * @author cartoon
 * @version 1.0
 */
class Solution {

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 according to first and second point,calculate initial slope
     *     2.2 calculate remain point with first point slope,compare with 2.1 slope
     * 3.About submit record
     *     3.1 0ms and 38.3MB memory in LeetCode China
     *     3.2 0ms and 42MB memory in LeetCode
     * 4.Q&A
     * @param coordinates
     * @return
     */
    public boolean checkStraightLine(int[][] coordinates) {
        double flag,temp;
        if(coordinates[1][0]==coordinates[0][0]){
            flag=Integer.MIN_VALUE;
        }
        else{
            flag=(double)(coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0]);
        }
        for(int i=2,length=coordinates.length;i<length;i++){
            if(coordinates[i][0]==coordinates[0][0]){
                temp=Integer.MIN_VALUE;
            }
            else{
                temp=(double)(coordinates[i][1]-coordinates[0][1])/(coordinates[i][0]-coordinates[0][0]);
            }
            if(temp!=flag){
                return false;
            }
        }
        return true;
    }
}
```
如果你有更好的想法或者疑问，可以到 [我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution) 提出issue，我会及时处理
你也可以关注 [我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution) 获得其他题目解题思路
