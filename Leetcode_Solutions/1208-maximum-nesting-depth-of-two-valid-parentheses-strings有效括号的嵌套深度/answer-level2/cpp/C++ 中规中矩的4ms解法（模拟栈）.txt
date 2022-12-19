```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int level = 0, N = seq.size();
        vector<int> res(N, 0);
        for (int i = 0; i < N; ++i){
            if (seq[i] == '(') res[i] = ++level % 2;
            else res[i] = level-- % 2;
        }
        return res;
    }
};
```