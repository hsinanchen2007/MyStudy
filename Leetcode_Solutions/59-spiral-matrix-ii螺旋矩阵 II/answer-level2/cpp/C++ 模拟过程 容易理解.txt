```
class Solution {
public:
  vector<vector<bool>> record;
  enum direction {
    right = 1,
    down,
    left,
    up
  };
  vector<int> getNextElemPosition(int n, int x, int y, direction prev_elem_dirc) {
    vector<int> res(3);
    if(prev_elem_dirc == right) {
      if ((y < n - 1) && (record[x][y + 1] == false)) {
        res[0] = x;
        res[1] = y + 1;
        res[2] = right;
      }
      else {
        res[0] = x + 1;
        res[1] = y;
        res[2] = down;
      }
    }
    else if (prev_elem_dirc == down) {
      if ((x < n - 1) && (record[x + 1][y] == false)) {
        res[0] = x + 1;
        res[1] = y;
        res[2] = down;
      }
      else {
        res[0] = x;
        res[1] = y - 1;
        res[2] = left;
      }
    }
    else if (prev_elem_dirc == left) {
      if ((y > 0) && (record[x][y - 1] == false)) {
        res[0] = x;
        res[1] = y - 1;
        res[2] = left;
      }
      else {
        res[0] = x - 1;
        res[1] = y;
        res[2] = up;
      }
    }
    else if (prev_elem_dirc == up) {
      if ((x > 0) && (record[x - 1][y] == false)) {
        res[0] = x - 1;
        res[1] = y;
        res[2] = up;
      }
      else {
        res[0] = x;
        res[1] = y + 1;
        res[2] = right;
      }
    }
    return res;
  }
  vector<vector<int>> generateMatrix(int n) {
    if (n <= 0) {
      return vector<vector<int>>();
    }
    vector<vector<int>> res = vector<vector<int>>(n, vector<int>(n, 0));
    record = vector<vector<bool>>(n, vector<bool>(n, false));
    vector<int> prev_elem_info(3);
    vector<int> cur_elem_info(3);
    prev_elem_info[0] = 0;
    prev_elem_info[1] = 0;
    prev_elem_info[2] = right;
    res[0][0] = 1;
    record[0][0] = true;
    int cnt = 2;
    while (cnt <= n * n) {
      cur_elem_info = getNextElemPosition(n, prev_elem_info[0], prev_elem_info[1], (direction)prev_elem_info[2]);
      prev_elem_info = cur_elem_info;
      res[cur_elem_info[0]][cur_elem_info[1]] = cnt;
      record[cur_elem_info[0]][cur_elem_info[1]] = true;
      cnt++;
    }
    return res;
  }
};
```
