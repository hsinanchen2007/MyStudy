### 解题思路
直接暴力遍历，遇到不是的剔除就行

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        vector<string> tmp = vector<string>(products.begin(), products.end());
        sort(tmp.begin(), tmp.end());
        for (int i=0; i<searchWord.size(); i++) {
            int j = 0;
            while (j < tmp.size()) {
                auto str = tmp[j];
                if (searchWord[i] == str[i]) {
                    j++;
                    continue;
                }
                tmp.erase(tmp.begin() + j);
            }
            
            res.emplace_back(vector<string>(tmp.begin(), tmp.size() > 3 ? tmp.begin()+3 : tmp.end()));
        }
        return res;
    }
};
```