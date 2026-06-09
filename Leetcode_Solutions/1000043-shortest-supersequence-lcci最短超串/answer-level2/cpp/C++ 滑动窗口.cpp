```c++
class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        unordered_set<int> actual;
        unordered_set<int> expect;
        for (int n : small) {
            expect.insert(n);
        }

        int n = big.size();
        int l = 0, r = 0;
        unordered_map<int, int> m;
        int left = 0, right = n + 1;

        while (r < n) {
            int i = big[r];
            m[i]++;

            if (expect.count(i)) {
                actual.insert(i);
            }

            while (actual == expect) {
                if (r - l < right - left) {
                    left = l;
                    right = r;
                }
                int t = big[l];
                if (expect.count(t)) {
                    m[t]--;
                    if (!m[t]) {
                        actual.erase(t);
                    }
                }
                l++;
            }

            r++;
        }
        if (right > n) {
            return {};
        }
        return {left, right};
    }
};
```