```
class Solution {
public:
    bool findRange(set<int>& s, int target, int& left, int& right) {
        if (s.empty())
            return false;
        auto p = s.equal_range(target);
        if (p.first == s.end()) { // target大于s的最大值
            left = *s.rbegin();
            right = -1;
        } else if (p.second == s.begin()) { // target小于s的最小值
            left = -1;
            right = *s.begin();
        } else { // target在s的两数中间或等于某数
            if (*p.first == target) {
                return false;
            }
            --p.first;
            left = *p.first;
            right = *p.second;
        }
        return true;
    }
    int kEmptySlots(vector<int>& bulbs, int K) {
        set<int> s;
        int left = -1;
        int right = -1;
        for (int i = 0; i < bulbs.size(); ++i) {
            if (findRange(s, bulbs[i], left, right) && 
                    (left > 0 && bulbs[i] - left == K + 1 || right > 0 && right - bulbs[i] == K + 1)) {
                return i + 1;
            }
            s.insert(bulbs[i]);
        }
        return - 1;
    }
};
```
