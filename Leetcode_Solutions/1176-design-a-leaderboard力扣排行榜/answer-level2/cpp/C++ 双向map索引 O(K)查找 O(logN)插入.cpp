```cpp
class Leaderboard {
public:
    map<int, int, greater<int>> reverseMap;
    unordered_map<int, int> scoreB;

    void addScore(int playerId, int score) {
        --reverseMap[scoreB[playerId]];
        scoreB[playerId] += score;
        ++reverseMap[scoreB[playerId]];
    }

    int top(int K) {
        int count = 0;
        int sum = 0;
        for (pair<int, int> p : reverseMap) {
            if (count + p.second <= K) {
                count += p.second;
                sum += p.second * p.first;
            }
            else {
                sum += (K - count) * p.first;
                break;
            }
        }
        return sum;
    }

    void reset(int playerId) {
        --reverseMap[scoreB[playerId]];
        scoreB[playerId] = 0;
    }
};
```
