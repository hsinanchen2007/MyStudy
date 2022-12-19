
```
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        std::vector<int> result(seq.size());
        int num = 0;
        for (int i = 1; i < seq.size(); ++i) {
            if (seq[i-1] == seq[i]) {
                num = num == 0 ? 1 : 0;
            }
            result[i] = num;
        }
        return result;
    }
};
```