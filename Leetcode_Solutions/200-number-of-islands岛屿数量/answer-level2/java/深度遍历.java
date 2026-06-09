1. 关于复杂度
    1.1 时间复杂度为O(n!)
    1.2 空间负责度为O(1)
2. 我的解题思路
    2.1 循环遍历每一个元素，有两种情况
        2.1.1 当前元素为1，深度遍历并改变相邻元素为0，自增result
        2.1.2 当前元素为0，继续下一遍历
<br />
#### java实现
```
/**
 * Problem
 *     200.Number of Islands
 *     https://leetcode.com/problems/number-of-islands/
 *     https://leetcode-cn.com/problems/number-of-islands/
 * Grade of difficulty
 *     Medium
 * Related topics
 * @author cartoon
 * @version 1.0
 */
class Solution{

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n!)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 circulate go though every element,there have two condition
     *         2.1.1 current element is 1,DFS to change behind element to 0,increase res
     *         2.1.2 current element is 0,keep going
     * 3.About submit record
     *     3.1 3ms and 42.3MB memory in LeetCode China
     *     3.2 1ms and 41MB memory in LeetCode
     * 4.Q&A
     *
     * @param grid
     * @return
     */
    public int numIslands(char[][] grid) {
        if(grid==null||grid.length==0){
            return 0;
        }
        int res=0;
        for(int i=0,length=grid.length;i<length;i++){
            for(int j=0,size=grid[i].length;j<size;j++){
                if(grid[i][j]=='1'){
                    mark(grid,i,j);
                    res++;
                }
            }
        }
        return res;
    }

    private void mark(char[][] grid,int i,int j){
        if(i<0||i==grid.length||j<0||j==grid[0].length||grid[i][j]!='1'){
            return;
        }
        grid[i][j]='0';
        mark(grid,i,j+1);
        mark(grid,i,j-1);
        mark(grid,i+1,j);
        mark(grid,i-1,j);
    }
}

```

#### php实现
```
class Solution{
    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n!)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 circulate go though every element,there have two condition
     *         2.1.1 current element is 1,DFS to change behind element to 0,increase res
     *         2.1.2 current element is 0,keep going
     * 3.About submit record
     *     3.1 48ms and 22.6MB memory in LeetCode China
     *     3.2 52ms and 22.6MB memory in LeetCode
     * 4.Q&A
     *
     * @param grid
     * @return
     */
    function numIslands($grid) {
        if($grid == null || count($grid) == 0){
            return 0;
        }
        $res = 0;
        for($i = 0, $length = count($grid); $i < $length; $i++){
            for($j = 0, $size = count($grid[$i]); $j < $size; $j++){
                if($grid[$i][$j] == "1"){
                    $this->mark($grid, $i, $j);
                    $res++;
                }
            }
        }
        return $res;
    }

    function mark(&$grid, $i, $j){
        if($i < 0 || $i == count($grid) || $j < 0 || $j == count($grid[0]) || $grid[$i][$j] != "1"){
            return;
        }
        $grid[$i][$j] = "0";
        $this->mark($grid, $i, $j + 1);
        $this->mark($grid, $i, $j - 1);
        $this->mark($grid, $i + 1, $j);
        $this->mark($grid, $i - 1, $j);
    }
}
```

如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出issue，我会及时处理
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路