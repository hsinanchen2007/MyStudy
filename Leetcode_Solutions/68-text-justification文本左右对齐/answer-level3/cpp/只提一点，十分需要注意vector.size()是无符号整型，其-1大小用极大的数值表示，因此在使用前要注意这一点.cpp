### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int len = words.size();
        vector<string> result;
        vector<string> mmv;
        int curWidth = maxWidth;
        for (auto iter : words) {
            if (curWidth < int(iter.size())) {
                string model;
                curWidth++;
                int spalen = max(int(mmv.size() - 1), 1);
                int minspa = curWidth / spalen + 1;
                int onemore = curWidth % spalen;
                string spa(minspa, ' ');
                for (auto childiter : mmv) {
                    model += childiter + spa;
                    if (onemore-- > 0) model.push_back(' ');
                }
                while (!mmv.empty()) mmv.pop_back();
                while (model.size()-maxWidth>0)model.pop_back();
                result.push_back(model);
                curWidth = maxWidth;
            }
            curWidth -= iter.size() + 1;
            mmv.push_back(iter);
        }
        if (!mmv.empty()) {
            string model;
            result.push_back(model);
            for (auto iter : mmv) result.back() += iter + ' ';
            result.back().pop_back();
            int morespace = maxWidth - result.back().size();
            while (morespace-->0) result.back().push_back(' ');
        }
        return result;
    }
};
```