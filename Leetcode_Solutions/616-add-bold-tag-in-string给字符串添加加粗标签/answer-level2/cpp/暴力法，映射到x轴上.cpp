### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<int> store(s.size(), 0);
        for (auto& str : dict) {
            int pos = s.find(str, 0);
            while (pos != string::npos) {
                for (int i = pos; i < pos + str.size(); ++i) {
                    ++store[i];
                }
                pos = s.find(str, pos + 1);
            }
        }
        string res;
        string part;
        for (int i = 0; i < store.size(); ++i) {
            if (store[i] > 0) {
                if (part.empty()) {
                    part += "<b>";
                }
                part.push_back(s[i]);
            } else if (store[i] == 0) {
                if (!part.empty()) {
                    part += "</b>";
                    res.append(part);
                    part.clear();
                }
                res.push_back(s[i]);
            }
        }
        if (!part.empty()) {
            part += "</b>";
            res.append(part);
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/5811a7c23d019e8f59fde904bf83407aa30937cdf2397d9b00f8553d25728973-image.png)
