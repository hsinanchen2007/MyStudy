### 解题思路
从rook起始位置开始，向上、下、左、右四个方向前进。

### 代码

```cpp
class Solution {
public:
  int numRookCaptures(vector<vector<char>>& board) {
    board_ = board; 
    int capture_num = 0;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (board[i][j] == 'R') {
          start_position_.push_back(i);
          start_position_.push_back(j);
          break;
        }
      }
    }
    // cout << "rook[i][j] " << start_position_[0] << " " << start_position_[1] << endl;
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (i == j || i == -j) {  // 注意只能出现{-1, 0} {1, 0} {0, -1} {0, 1}四种情况
          continue;
        }
        vector<int> step = {i, j};
        capture_num += move(step);
      } 
    }

    return capture_num;
  }

private:
  int move(vector<int> step) {
    vector<int> current_position = start_position_;
    // cout << "start[i][j] = " << current_position[0] << " " << current_position[1] << endl;
    while (true) {
      current_position[0] += step[0];
      current_position[1] += step[1];
      // cout << "  curr[i][j] = " << current_position[0] << " " << current_position[1] << endl;
      if (current_position[0] >= 0 && current_position[0] < 8 && current_position[1] >= 0 && current_position[1] < 8) {
        char current_target = board_[current_position[0]][current_position[1]];
        if (current_target == 'B') {
          return 0;
        } else if (current_target == 'p') {
          // cout << "  find one!" << endl;
          return 1;
        } else {
          continue;
        }
      } else {
        return 0;
      }
    }
  }

  vector<vector<char>> board_;
  vector<int> start_position_;
};
```