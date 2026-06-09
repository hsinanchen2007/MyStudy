```
class Solution {
public:
    // 回溯，分别按升序和降序寻找组合。
    const int INF = 1e5+1;
    void increaseBackTracking(int pre, int curr, int begin, int size, vector<int>& rating, int& result) {
        if (curr == 3) {
            result += 1;
            return;
        }
        for (int i = begin; i < size; ++i) {
            // 不满足升序条件，直接看下一个数
            if (rating[i] <= pre) continue;
            // 满足升序，已选数+1
            curr++;
            // 寻找下一位
            increaseBackTracking(rating[i], curr, i+1, size, rating, result);
            // 退回选择前的状态
            curr--;
        }
    }
    
    void decreaseBackTracking(int pre, int curr, int begin, int size, vector<int>& rating, int& result) {
        if (curr == 3) {
            result += 1;
            return;
        }
        for (int i = begin; i < size; ++i) {
            if (rating[i] >= pre) continue;
            curr++;
            decreaseBackTracking(rating[i], curr, i+1, size, rating, result);
            curr--;
        }
    }
    
    int numTeams(vector<int>& rating) {
        int size = (int)rating.size();
        if (size == 0) return 0;
        int result = 0;
    
        increaseBackTracking(0 ,0, 0, size, rating, result);
        decreaseBackTracking(INF, 0, 0, size, rating, result);
        return result;
    }
};
```
