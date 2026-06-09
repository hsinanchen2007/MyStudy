```
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ret;
        if (searchWord.size() == 0) {
            return ret;
        }
        sort(products.begin(), products.end());
        int start = 0;
        int end = products.size();
        bool go = true;
        for (int i = 0; i < searchWord.size(); i++) {
            bool inrange = false;
            int count = 0;
            vector<string> ans;
            
            for (int j = start; j < end && go; j++) {
                if (i >= products[j].size()) {
                    continue;
                }
                if (searchWord[i] == products[j][i]) {
                    cout << "i " << i << " j " << j << " start " << start << " end " << end << " inrange " << inrange << " count " << count << endl;
                    if (!inrange) {
                        start = j;
                        inrange = true;
                    }
                    if (count < 3) {
                        ans.emplace_back(products[j]);
                        count++;
                    }
                } else if (inrange) {
                    end = j;
                    break;
                }
            }
            ret.emplace_back(ans);
            if (ans.empty()) {
                go = false;
            }
        }
        return ret;
    }
};
```
