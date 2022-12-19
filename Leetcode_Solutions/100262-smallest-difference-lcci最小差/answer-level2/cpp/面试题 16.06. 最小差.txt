
```
class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(b.begin(), b.end());
        long res = INT_MAX;
        for(auto& i : a) {
            int idx = Find(b, i);
            res = min(res, abs((long)b[idx] - (long)i));
            if(res == 0) {
                return 0;
            }
            if(idx + 1 < b.size()) {
                res = min(res, abs((long)b[idx + 1] - (long)i));
            }
        }
        return res;
    }
private:
    int Find(vector<int>& b, int i) {
        if(i <= b[0]) {
            return 0;
        } else if(i >= b[b.size() - 1]) {
            return b.size() - 1;
        }
        int l = 0;
        int r = b.size() - 1;
        while(l + 1 < r) {
            int idx = (l + r) / 2;
            if(i < b[idx]) {
                r = idx;
            } else if(i > b[idx]) {
                l = idx;
            } else {
                return idx;
            }
        }
        return l;
    }
};
```
