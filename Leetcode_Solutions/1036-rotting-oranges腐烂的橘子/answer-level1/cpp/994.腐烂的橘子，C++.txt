### 解题思路

笨办法，先记录一下吧😅（内存消耗 :15.2 MB, 在所有 C++ 提交中击败了5.40%的用户）

我不确定有没有不用模拟橘子被感染的办法，如果有的话我觉得应该会更好一些。我一上来想到的就是模拟橘子被感染的整个过程，所以需要逐个橘子判断它的当前状态，然后判断它的上下左右的橘子的状态，如果存在需要感染的情况就修改某个橘子的状态。

我定义了一个同样大小的二维数组用来作为状态记录表(这里是主要占用内存的地方)，初始化为全0，其中的整数即表示分钟数

另外定义了一个函数用于判断橘子是否全部腐烂，或者还有橘子可以被感染，或是存在不可能被感染的橘子。

### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minute = 0;
        size_t rows = grid.size();//行数
        size_t cols = grid[0].size();//列数
        vector<int> temp(cols);//仅用于初始化状态记录表
        vector<vector<int>> record(rows, temp);//状态记录表，初始化为全0，数字0，1，2表示第0，1，2步
        
        //模拟橘子随时间被感染
        while (isInfectionOver(grid) == 1)
        {
            minute++;//分钟数+1
            //同步遍历橘子网格与状态记录表
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    if (grid[i][j] == 2 && record[i][j] < minute) {
                        record[i][j] = minute;
                        //感染上侧橘子
                        if (i > 0 && grid[i - 1][j] == 1) {
                            grid[i - 1][j] = 2;
                            record[i - 1][j] = minute;
                        }
                        //感染下侧橘子
                        if (i < rows - 1 && grid[i + 1][j] == 1) {
                            grid[i + 1][j] = 2;
                            record[i + 1][j] = minute;
                        }
                        //感染左侧橘子
                        if (j > 0 && grid[i][j - 1] == 1) {
                            grid[i][j - 1] = 2;
                            record[i][j - 1] = minute;
                        }
                        //感染右侧橘子
                        if (j < cols - 1 && grid[i][j + 1] == 1) {
                            grid[i][j + 1] = 2;
                            record[i][j + 1] = minute;
                        }
                    }
                }

            }
        }
        return isInfectionOver(grid) == 2 ? -1 : minute;
    }

    //是否感染结束，可能的返回值为0，1，2
    //0表示所有橘子都已腐烂；1表示仍存在可以被感染的橘子；2表示存在不可能被感染的橘子
    int isInfectionOver(vector<vector<int>>& grid) {
        int ret = 0;//作为返回值
        size_t rows = grid.size();//行数
        size_t cols = grid[0].size();//列数
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[i].size(); j++) {
                //只需判断表中的新鲜橘子是否可能被感染
                if (grid[i][j] == 1) {
                    ret = 2;//此处默认这个橘子不可能被感染
                    //上侧有腐烂橘子
                    if (i > 0 && grid[i - 1][j] == 2)
                        return 1;
                    //下侧有腐烂橘子
                    if (i < rows - 1 && grid[i + 1][j] == 2)
                        return 1;
                    //左侧有腐烂橘子
                    if (j > 0 && grid[i][j - 1] == 2)
                        return 1;
                    //右侧有腐烂橘子
                    if (j < cols - 1 && grid[i][j + 1] == 2)
                        return 1;
                }
            }
        }
        return ret;
    }
};
```