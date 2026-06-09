```
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadset(deadends.begin(), deadends.end());
        if (deadset.count("0000") || deadset.count(target)) {
            return -1;
        }
        vector<string> movesToTarget;
        auto moves = getValidMoves(target);
        for (auto& move : moves) {
            if (!deadset.count(move)) {
                movesToTarget.push_back(move);
            }
        }
        // 可以直接从deadends中看出target可不可达
        if (movesToTarget.empty()) {
            return -1;
        }
        // 最大步长是40步（每位转动10次）
        int min_stride = 40;
        // 计算到达每个可达结果的步长，取最小
        for (auto& move : movesToTarget) {
            int cur_stride = 0;
            for (int i = 0; i < 4; ++i) {
                int turns = move[i] - '0';
                // 可以倒着转，所以转动次数不会大过5
                if (turns > 5) {
                    turns = 10 - turns;
                }
                cur_stride += turns;
            }
            if (cur_stride < min_stride) {
                min_stride = cur_stride;
            }
        }
        // 最后加上到达target的那一步
        return min_stride + 1;
    }

    vector<string> getValidMoves(const string& sequence) {
        vector<string> moves;
        for (int i = 0; i < 4; i++) {
            string temp = sequence;
            // +1
            temp[i] = temp[i] == '9' ? '0' : temp[i] + 1;
            moves.push_back(temp);
            // -1
            temp = sequence;
            temp[i] = temp[i] == '0' ? '9' : temp[i] - 1;
            moves.push_back(temp);
        }
        return moves;
    }
};
```
