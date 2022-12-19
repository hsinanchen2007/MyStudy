```
vector<int> divingBoard(int shorter, int longer, int k) {
        if(k <= 0) return {};
        if(shorter == longer) return vector<int>(1,k * shorter);
        vector<int> ans;
        for(int i = 0; i <= k; i++)
        {
            ans.push_back((k - i) * shorter + i * longer);
        }
        return ans;
    }
```
