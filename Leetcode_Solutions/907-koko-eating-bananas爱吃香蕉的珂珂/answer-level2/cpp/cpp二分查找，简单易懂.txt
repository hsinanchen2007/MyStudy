```
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1, right;
        initLeftRight(piles, right);
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, mid, H)) {
                right = mid;
            } else { // eat too slow, need to accelerate
                left = mid + 1;
            }
        }
        return left;
    }
    void initLeftRight(vector<int>& piles, int& right) {
        for (auto& val : piles) {
            right = max(right, val);
        }
    }
    bool canFinish(vector<int>& piles, int speed, int H) {
        int hours = 0;
        for (auto& val : piles) {
            hours += val / speed + (val % speed ? 1 : 0);
            if (hours > H) return false;
        }
        return true;
    }
};
```
