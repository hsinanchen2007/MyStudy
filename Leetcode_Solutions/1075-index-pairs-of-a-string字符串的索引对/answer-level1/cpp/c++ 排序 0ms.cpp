![image.png](https://pic.leetcode-cn.com/07d6bfb00f6ede93a34341fecf3408caea9af20debfd0a29244b8745a0e930f1-image.png)

思路：
1.遍历words，把find到的所有结果放入结果
2.排序，over

```
class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> result;
        for (const auto& word : words) {
            int pos = text.find(word);
            while (pos != -1) {
                result.emplace_back(vector<int>{pos, pos + word.length() - 1});
                pos = text.find(word, pos + 1);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};
```
