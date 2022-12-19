学习了各位大神的解答，发现应该还有更简单的判断约束方法：
1、1~9中数字有且仅出现一次；
2、中间数字为5，原因不再赘述；
3、四周，第一、三行；第一、三列 的和为15。
以上两个约束条件即可，代码见最后。

leetcode这里的验证示例集有缺陷，前面看到验证三行和为15，两个对角和为10的解法，自己试了下，发现存在不是幻方但是满足条件的情况：
1  8  6
3  5  7
4  2  9

幻方中四个对角必须是偶数，原因：
1、首先中间为5则四周经过中间的连线上除5外两个数必是（1,9）（2,8）（3,7）（4,6）4组情况（和才能是15）。
2、各行各列和为15，需要两个偶数+一个奇数、或者三个奇数才能得到，而0~9中仅有4个偶数，除5之外也仅有4个奇数；由1可知，除了经过中间的连线，不会出现3个奇数连成一线的情况。于是四周的两行两列均是两个偶数+一个奇数的情况，两行两列中各需要两个偶数，那么偶数仅能在四个角上。

当一个矩阵满足0~9，中间数字为5时，且四周和为15时，一定满足偶数在四个角上，且（2,8）（4,6）对角，满足上面的条件后，剩余4个奇数被相邻的偶数固定，所以满足前面说的中间5，四周和15即可。


代码如下：
class Solution {
public:
    bool valid(vector<vector<int>>& grid, int i, int j){
        if(grid[i+1][j+1] != 5) return false;
        
        int temp_hash[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        for(int offi = 0; offi < 3; offi++){
            for(int offj = 0; offj < 3; offj++){
                if(grid[i+offi][j+offj]>0 and grid[i+offi][j+offj]<10){
                    temp_hash[grid[i+offi][j+offj] - 1] = 1;
                }
                else
                    return false;
            }
        }
        int count = 0;
        for(int index = 0; index < 9; index++){
            count += temp_hash[index];
        }
        if(count != 9) return false;

        if((grid[i][j] + grid[i][j+1] + grid[i][j+2] != 15)
        or (grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2] != 15) 
        or (grid[i][j] + grid[i+1][j] + grid[i+2][j] != 15) 
        or (grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2] != 15))
            return false;
        else
            return true;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.size();

        if (cols < 3 or rows < 3) return 0;
        int count = 0;
        for (int r = 0; r < rows - 2; r++){
            for (int c = 0; c < cols - 2; c++){
                if(valid(grid, r, c)) count++;
            }
        }
        return count;
    }
};