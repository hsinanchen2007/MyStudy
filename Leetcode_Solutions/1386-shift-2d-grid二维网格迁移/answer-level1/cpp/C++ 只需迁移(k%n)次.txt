主要思路：一次次的迁移肯定是慢的，快捷的方法就是只做有必要的迁移，实际上可以发现，当迁移次数为grid[0].size()时，相当于把grid的最后一个元素移到最前面。

具体步骤如下：

1. 先计算m，n的值；
2. 求(k/n)%m，k%n的值
3. 先做移项，实际上必须做的移项次数是小于m的；
4. 再做迁移，实际上必须做的迁移次数是小于n的；

完整代码：
```
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if (k <= 0 || k > 100) {return grid;}

        int m = grid.size();
        int n = grid[0].size();
        int epoch = (k / n) % m;
        int move = k % n;

        while(epoch--)
        {
            grid.insert(grid.begin(), grid.back());
            grid.pop_back();
        }

        while(move--)
        {
            int last = grid[m-1][n-1];
            for (auto &vec : grid)
            {
                vec.insert(vec.begin(), last);
                last = vec.back();
                vec.pop_back();
            }
        }

        return grid;
    }
};
```
￼![image.png](https://pic.leetcode-cn.com/28113abba17e228cb4a5897973aaa4990a6b18783e7ea840504897f8c5aebc56-image.png)
