### 解题思路
利用哈希表存储文件内容对应的路径集合，然后查找哈希表得到最终结果

### 代码

```cpp
class Solution {
public:
    vector<string> split(const string& s, char sep) {
        string t;
        vector<string> res;
        for (auto c : s) {
            if (c == sep) {
                res.push_back(t);
                t.clear();
            } else {
                t += c;
            }
        }
        res.push_back(t);
        return res;
    }
    void helper(const string& s, unordered_map<string, vector<string> >& m) {
        vector<string> v = split(s, ' ');
        string& dir = v[0];
        for (int i = 1; i < v.size(); ++i) {
            vector<string> v1 = split(v[i], '(');
            string& file = v1[0];
            string& content = v1[1];
            content.pop_back();
            m[content].push_back(dir + "/" + file);
        }
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string> > m;
        for (auto& s : paths) {
            helper(s, m);
        }
        vector<vector<string> > res;
        for (auto& p : m) {
            if (p.second.size() > 1) {
                res.push_back(p.second);
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/7ae318db31fcadece53ac7a2875e1556f626e78aa6f5090108b8b3012c336b76-image.png)
