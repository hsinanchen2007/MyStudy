### 解题思路
引用liweiwei1419大神的一句话，**用回溯法解问题前一定要先画出递归树**，这样有助于理清思路，方便代码实现，虽然有时候会"误入歧途"，但我相信殊途同归，感谢大神liweiwei1419，回溯法60个题快做完了，靠的就是这句话和回溯法解题的模板。

本文题解中没有画出，希望大家心里都有数，如果没有，对树做个简单描述：
1，把每个3*3的小格子中未填数据放到一个集合中，对它进行全排列的回溯，即会覆盖所有填充情况
2，总共有9个这样的格子。
3，所以想象一下，整个树的root为空，第二层的子树root为第一个小格子中每个未填数据，即每个数据为一个子树的root；在第一个小格子未填数据全部填满，其全排列的每个叶子几点连接的都是第二个小格子的未填数据...想到这里，我已感觉力不从心，思路隐约有些不清楚，可能会误入歧途或者说走火入魔，但这个路是自己选择的，含着泪也要走完，导致我连写带改加调试，花了3个多小时，还是有可优化的地方。

好的，废话有点多了：
1，获取每个3*3小格子的未填数据集合，即get_set
2，判断每个集合中全排列的位置是否满足整行或者整列不重复的约束，即valid
3，按照递归树实现即可。

其中：
point：表示未填数据的坐标x，y和待填数据val
其它见注释

主要用到的回溯法基本模板有两个，琢磨明白后，大部分代码都可以复用，只是需要修改些约束条件和针对问题的优化剪枝方法不同：
1，基于全排列或8皇后的经典问题模板，用swap技巧或者是当前剩余可遍历的集合。本质就是多叉树的先序和后续遍历
2，子集问题，2的n次幂问题。

记性好的时候不总结，总结的时候记性差。

### 代码

```cpp
class Solution {
public:
    class point {
      public:
        point(int a, int b, int c) {
          x = a;
          y = b;
          val = c;
        }

        // 记录整个表格中未填数据的坐标，val表示可以填的候选值
        int x;
        int y;
        int val;
    };

    // row 和 col 表示9个小格子的坐标，[0,0] ~ [2,2]
    // 函数获取每个3*3小格子的未填数据集合
    vector<point> get_set(int row, int col, vector<vector<char>>& board) {
      int basex = 3 * row;
      int basey = 3 * col;
      int s = 0;
      vector<point> res;
      for (int i = 0; i < 9; ++i) {
        int tmpx = i / 3;
        int tmpy = i % 3;
        int x = basex + tmpx;
        int y = basey + tmpy;
        if (board[x][y] != '.') {
          s |= 1 << (board[x][y] - '0');
        } else {
          res.push_back(point(x, y, 0));
        }
      }

      for (int i = 1, j = 0; i <= 9; ++i) {
        if ((1 << i) != (s & (1 << i))) {
          res[j++].val = i;
        }
      }

      return res;
    }

    // 判断target是否可以填到全局坐标x y位置
    bool valid(int target, int x, int y, vector<vector<char>>& board) {
      for (int i = 0; i < 9; ++i) {
        if (board[x][i] - '0' == target || board[i][y] - '0' == target) {
          return false;
        }
      }
      return true;
    }

    // num 表示第几个3*3的小格子，索引从0开始
    // data表示第num个小格子中未填数据集合
    // level 表示data中数据全排列的起始index
    bool backtrace(int num, int level, vector<point> data, vector<vector<char>>& board) {
      // 每个3*3小格子的全排列路径和回溯
      for (int k = level; k < data.size(); ++k) {
        // 获取位置信息，注意不是data[k]，因为这里面未填充的坐标x，y是不变的，变的是它对于的val
        int x = data[level].x;
        int y = data[level].y;
        if (valid(data[k].val, x, y, board)) {
          swap(data[k].val, data[level].val);
          // 标准的全排列回溯
          board[x][y] = data[level].val + '0';
          if (backtrace(num, level + 1, data, board)) {
            return true;
          }
          board[x][y] = '.';
          swap(data[k].val, data[level].val);
        }
      }

      // 3*3的小格子全都填好数据后，考虑进行下一个3*3格子的遍历，或者是>=9停止遍历
      if (level == data.size()) {
        num += 1;

        if (num >= 9) {
          return true;
        }

        // 更新下一个格子中未填数据集合
        int new_row = (num) / 3;
        int new_col = (num) % 3;
        vector<point> new_data = get_set(new_row, new_col, board);
        return backtrace(num, 0, new_data, board);
      }

      return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
      vector<point> data = get_set(0, 0, board);
      backtrace(0, 0, data, board);
    }
};
```