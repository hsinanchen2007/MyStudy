思路很简单，细节是处理好最后一行。
不是很简洁，凑合看吧

```
class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<pair<int, int>> board;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                board.push_back(make_pair(i, j));
            }
        }
        board.push_back(make_pair(5, 0));

        string ans;
        int cur_ch = 0;
        pair<int ,int> cur_pos= board[0];
        for (char next_ch : target)
        {
            pair<int, int> next_pos = board[next_ch - 'a'];
            int right = next_pos.second - cur_pos.second;
            int left = cur_pos.second - next_pos.second;
            int up = cur_pos.first - next_pos.first;
            int down = next_pos.first - cur_pos.first;

            // 如果目标点是最后一行，先处理左右的情况
            if(next_pos.first == 5)
            {
                ans.append(right > 0 ? string(right, 'R') : string(left, 'L'));
                ans.append(up > 0 ? string(up, 'U') : string(down, 'D'));
            }
            // 如果起始点是最后一行，先处理上下的情况
            else if(cur_pos.first == 5)
            {
                ans.append(up > 0 ? string(up, 'U') : string(down, 'D'));
                ans.append(right > 0 ? string(right, 'R') : string(left, 'L'));
            }
            else // 其余情况两者均可
            {
                ans.append(right > 0 ? string(right, 'R') : string(left, 'L'));
                ans.append(up > 0 ? string(up, 'U') : string(down, 'D'));
            }
            
            ans.push_back('!');
            
            cur_ch = next_ch;
            cur_pos = next_pos;
        }

        return ans;
    }
};
```
