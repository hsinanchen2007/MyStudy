回溯法：
1，寻找board的颜色交替处，在hand中找到对应的颜色，看是否可以补全缺数
2，当某一步的使用球数目已经大于等于了全局最小值，就可以剪枝退出了
```
class Solution {
public:
    string boom(string s, int i) {
        if (s.empty()) return "";
        int left = i, right = i;
        while (left > 0 && s[left - 1] == s[left]) --left;
        while (right < s.size() - 1 && s[right + 1] == s[right]) ++right;
        if (right - left + 1 >= 3) {
            s = s.substr(0, left) + s.substr(right + 1);
            return boom(s, max(left - 1, 0));
        }
        return s;
    }
    void backtrace(string board, map<char, int>& hand, int ball, int remain, int& min_ball) {
        if (board.empty()) {
            min_ball = min(min_ball, ball);
            return;
        }
        if (ball >= min_ball || remain == 0 || min_ball == 0) return;
        string s;
        int left = -1;
        for (int i = 0; i < board.size(); ++i) {
            if (i == board.size() - 1 || board[i] != board[i + 1]) {
                int lack = 3 - (i - left);
                if (hand[board[i]] >= lack) {
                    hand[board[i]] -= lack;
                    s = board;
                    s.insert(i, lack, board[i]);
                    s = boom(s, i);
                    backtrace(s, hand, ball + lack, remain - lack, min_ball);
                    hand[board[i]] += lack;
                }
                left = i;
            }
        }
    }
    int findMinStep(string board, string hand) {
        map<char, int> m;
        for (auto c : hand) ++m[c];
        int res = INT_MAX;
        backtrace(board, m, 0, hand.size(), res);
        return (res == INT_MAX) ? -1 : res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/8779bd818ad64321a390f31f5b32f90adc1f9ab608d217bc44ff36f124a2556e-image.png)
