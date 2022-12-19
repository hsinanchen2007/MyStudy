```class Solution {
public:
    unordered_map<int, vector<int>> mlv;
    unordered_map<int, vector<int>> mvl;
    map<int, int> mli;
    vector<int> res;
    int ans = 0;
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        int n = values.size();
        for(int i = 0; i < n; ++i) {
            mlv[labels[i]].emplace_back(values[i]);
            mvl[values[i]].emplace_back(labels[i]);
            mli[labels[i]] = 0;
        }
        sort(values.begin(), values.end());
        for(int i = 0, j = n - 1; i < num_wanted && j >= 0; ) {
            for(int k = 0;j>=0&& k < mvl[values[j]].size()&&i < num_wanted; ++k,--j)
                if(mli[mvl[values[j]][k]] < use_limit) {
                    res.emplace_back(values[j]);
                    ++mli[mvl[values[j]][k]];
                    ++i;
                }
        }
        for(int i = 0; i < res.size(); ++i)
            ans += res[i];
        return ans;
    }
};```