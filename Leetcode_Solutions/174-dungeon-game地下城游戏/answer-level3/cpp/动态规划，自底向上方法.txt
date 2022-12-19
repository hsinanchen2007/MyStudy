思路：因为骑士只能向下或向右走，当骑士在最后一行时，如果安全的通过最后一行，其生命值只和最后一行的值相关。同理，当骑士不在最后一行时，其生命值只和其当前行的剩余位置值以及下一行的值相关。所以可以从公主的位置开始，自底向上，循环更新骑士的生命值。骑士应选择扣生命值小的那一条路行走。

需要注意的是，当遇到生命值增加，且需要扣掉的生命值为正数时，应该将其归零，意思是骑士到这一格时只需1点生命值，即可遇到公主。

最后将计算出的骑士在第一格的生命值取负加一，即为所需生命值。

```c
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //  m 为行数，n 为列数
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        //  初始化一个数组用于更新需要被扣掉生命值（以下简称生命值）
        vector<int> line(n, INT32_MIN);
        line[n - 1] = 0;
        
        //  从最后一行的最右边开始更新生命值
        for (int i = m - 1; i >= 0; i--) {
            line[n - 1] += dungeon[i][n - 1];
            line[n - 1] = (line[n - 1] > 0) ? 0 : line[n - 1];

            for (int j = n - 2; j >= 0; j--) {
                line[j] = max(line[j], line[j + 1]) + dungeon[i][j];
                line[j] = (line[j] > 0) ? 0 : line[j];
            }
        }
        return 1 - line[0];
    }
};
```