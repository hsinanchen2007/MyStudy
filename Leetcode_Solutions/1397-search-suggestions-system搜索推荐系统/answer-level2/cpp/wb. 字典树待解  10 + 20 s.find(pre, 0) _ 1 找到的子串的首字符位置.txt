### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        string pre;
        vector<vector<string>> ans;
        for (int i = 0; i < searchWord.size(); i++) {
            pre += searchWord[i];
            vector<string> tmp;
            for (auto s : products) {
                if (s.find(pre, 0) < 1) {
                    tmp.emplace_back(s);
                    if (tmp.size() >= 3) {
                        break;
                    }
                }
            }
            ans.emplace_back(tmp);
        }
        return ans;
    }
};
```