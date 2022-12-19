```
/*
* Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
* Description: i love leetcode
* Author: Nicolas
* Create: 2019/12/10
*/

class Solution {
public:

    string alphabetBoardPath(string target)
    {
        map<char, pair<int, int >> board;
        InitializeBoard(board);
        return CalcBoardPath(target, board);
    }

private:

    string CalcBoardPath(string &target, map<char, pair<int, int>> board)
    {
        string result;
        pair<int, int> now = { 0, 0 };
        for (int i = 0; i < target.size(); ++i) {
            char c = target.at(i);
            if (now == board.at(c)) {
                result.push_back('!');
                continue;
            }

            char next = c;
            if (c == 'z') {
                next = 'u';
            } else {
                if (now == board.at('z')) {
                    result.push_back('U');
                    now = board.at('u');
                }
            }
            CalcBoardNext(board, next, now, result);
            if (c == 'z') {
                result.push_back('D');
                now = board.at(c);
            }
            result.push_back('!');
        }
        return result;
    }

    void CalcBoardNext(map<char, pair<int, int>> &board, char c, pair<int, int> &now, string &result)
    {
        pair<int, int> dest = board[c];
        if (dest.first > now.first) {
            for (int i = 0; i < (dest.first - now.first); ++i) {
                result.push_back('D');
            }
        } else if (dest.first < now.first) {
            for (int i = 0; i < (now.first - dest.first); ++i) {
                result.push_back('U');
            }
        }

        if (dest.second > now.second) {
            for (int i = 0; i < (dest.second - now.second); ++i) {
                result.push_back('R');
            }
        } else if (dest.second < now.second) {
            for (int i = 0; i < (now.second - dest.second); ++i) {
                result.push_back('L');
            }
        }
        now = dest;
    }

    void InitializeBoard(map<char, pair<int, int>> &board)
    {
        board['a'] = make_pair(0, 0);
        board['b'] = make_pair(0, 1);
        board['c'] = make_pair(0, 2);
        board['d'] = make_pair(0, 3);
        board['e'] = make_pair(0, 4);

        board['f'] = make_pair(1, 0);
        board['g'] = make_pair(1, 1);
        board['h'] = make_pair(1, 2);
        board['i'] = make_pair(1, 3);
        board['j'] = make_pair(1, 4);

        board['k'] = make_pair(2, 0);
        board['l'] = make_pair(2, 1);
        board['m'] = make_pair(2, 2);
        board['n'] = make_pair(2, 3);
        board['o'] = make_pair(2, 4);

        board['p'] = make_pair(3, 0);
        board['q'] = make_pair(3, 1);
        board['r'] = make_pair(3, 2);
        board['s'] = make_pair(3, 3);
        board['t'] = make_pair(3, 4);

        board['u'] = make_pair(4, 0);
        board['v'] = make_pair(4, 1);
        board['w'] = make_pair(4, 2);
        board['x'] = make_pair(4, 3);
        board['y'] = make_pair(4, 4);

        board['z'] = make_pair(5, 0);
    }
};
```
