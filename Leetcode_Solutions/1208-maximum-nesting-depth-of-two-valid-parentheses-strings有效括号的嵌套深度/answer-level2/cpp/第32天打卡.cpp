抄作业
```
class Solution {

public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> r;
        for (int i = 0; i < (int)seq.size(); ++i) {
            r.push_back(i & 1 ^ (seq[i] == '('));
        }
        return r;
    }
};
```
