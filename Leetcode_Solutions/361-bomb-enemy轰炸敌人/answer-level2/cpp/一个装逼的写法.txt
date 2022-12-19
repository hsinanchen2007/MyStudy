

    这个代码太装逼了，我从leetcode英文官网抄来的。
    https://leetcode.com/problems/bomb-enemy/discuss/83387/Short-O(mn)-time-O(n)-space-solution
    两个装逼点
    第一，为什么 if (j == 0 || grid[i][j-1] == 'W') 
        也就是说是从第一行，第一列，和碰到wal才开始算。
    第二，为什么colhits要用数组
    反正我是看的一愣一愣的，并且还没加任何注释。

    你觉得我是觉得这个代码牛逼？？
    不，我是来喷这种做法的。
    之后这种弯弯绕绕，不加注释的代码，看不懂就不要看了。
    因为，思路并不一定复杂，复杂的是他的写法。加了注释，很快就能看懂了。

    这种就跟茴香豆的茴有几种写法一样。
    有时间可以玩玩，就跟玩数独一样，没时间就跳过吧。
    工作中这么写代码，你绝壁会被后面维护这块代码的人给喷死。
```
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        int result = 0, rowhits, colhits[n];
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (j == 0 || grid[i][j-1] == 'W') {
                    rowhits = 0;
                    for (int k=j; k<n && grid[i][k] != 'W'; k++)
                        rowhits += grid[i][k] == 'E';
                }
                if (i == 0 || grid[i-1][j] == 'W') {
                    colhits[j] = 0;
                    for (int k=i; k<m && grid[k][j] != 'W'; k++)
                        colhits[j] += grid[k][j] == 'E';
                }
                if (grid[i][j] == '0')
                    result = max(result, rowhits + colhits[j]);
            }
        }
        return result;
    }
};
```

