
一共9行9列9个box(3x3). 三个变量标记每行每列每个box的状态。
每行每列每个box有共同特征，都最多只有9个数字，所以内部用一个size=9数组status盛放。
综上，三个变量实际变成了三个二维数组。默认初始化为0，标示当前行列或者box中还没有存放任何数字

- 循环遍历输入数据：
-   如有效，则必然是1~9。
-       对应数组status下标0~8。
-   如果对应的status已经被标记 1
-       则表明有重复。返回错误。
-   否则说明还未发现重复
-       将行列和box对应下标的状态为 1

```cpp
#define SDK_SIZE 9
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rs = board.size();
        if (rs != SDK_SIZE) { return false; }
        int cs = board[0].size();
        if (cs != SDK_SIZE) { return false; }
        vector<vector<unsigned char >> rows(SDK_SIZE, vector<unsigned char>(SDK_SIZE));
        vector<vector<unsigned char >> cols(SDK_SIZE, vector<unsigned char>(SDK_SIZE));
        vector<vector<unsigned char >> boxes(SDK_SIZE, vector<unsigned char>(SDK_SIZE));
        for (int r = 0; r < rs; r++) {
            for (int c = 0; c < cs; c++) {
                if (board[r][c] == '.') { continue; }
                // cout << "(" << r << ", " << c << "): " << board[r][c] << endl;
                unsigned int v = board[r][c] - '1';
                if (v >= SDK_SIZE) { return false; }
                int box = (r / 3) * 3 + (c / 3); // index = (r % 3) * 3 + (c % 3);
                if ( rows[r][v] != 0 || cols[c][v] != 0 || boxes[box][v] != 0) { return false; }
                rows[r][v] = cols[c][v] = boxes[box][v] = 1;
            }
        }
        return true;
    }
};
```
