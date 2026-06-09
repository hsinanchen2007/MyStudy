Intersection of 2 linked lists
```
class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string &r1, string &r2) {
        unordered_set<string> p1;
        unordered_map<string, string> next;
        for (auto &r : regions) {
            for (int i = 1; i < r.size(); ++i) {
                next[r[i]] = r[0];
            }
        }
        string p = r1;
        while (!p.empty()) {
            p1.insert(p);
            p = next[p];
        }
        p = r2;
        while (!p1.count(p)) {
            p = next[p];
        }
        return p;
    }
};
```