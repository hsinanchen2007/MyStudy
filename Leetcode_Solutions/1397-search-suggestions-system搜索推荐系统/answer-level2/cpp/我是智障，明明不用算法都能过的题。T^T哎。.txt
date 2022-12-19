# 核心思想
首先将products按照字典序排序，sort一行搞定。。。
然后针对每一个word，如"m", "mo", "mou", "mous", "mouse"，遍历products，找到前3个满足条件的结果即可。。。

```
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        sort(products.begin(), products.end()); // 将products按照字典序排序
        for (int i = 1; i <= searchWord.size(); i++) {
            int num = 0; // 当前找到的product个数
            string word = searchWord.substr(0, i); // "m", "mo", "mou", "mous", "mouse"
            vector<string> oneResult;
            for (auto s : products) {
                if (num < 3) {
                    // 当前找到的product不满3个
                    size_t found = s.find(word);
                    if (found != string::npos) {
                        // word是当前product的子串
                        if (found == 0) {
                            // word是当前product的前缀子串
                            oneResult.push_back(s);
                            num++; 
                        }
                    }
                } else {
                    // 当前找到的product已经满3个了
                    break;
                }
            }
            result.push_back(oneResult);
        }
        return result;
    }
};
```
