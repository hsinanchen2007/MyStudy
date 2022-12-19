### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    static bool myCmp(pair<string, int> a, pair<string, int> b)
    {
        if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return a.second > b.second;
        } 
    }
    string longestWord(vector<string>& words) {
        string ret = "";
        vector<pair<string, int>> order;
        for (auto i : words) {
            order.push_back(pair<string, int>(i, i.size()));
        }
        sort(order.begin(), order.end(), myCmp);
        vector<string> tmp;
        for (auto i : order) {
            tmp.push_back(i.first);
        }
        // 最大长度为1的情况	
        if (tmp.begin()->size() == 1) {
            return *tmp.begin();
        }
        // 最大长度不为1的情况
        for (auto i : tmp) {
            int flag = true;
            string buf = i.substr(0, i.size()-1);
            while (buf.size() >= 1) {
                if (find(tmp.begin(), tmp.end(), buf) == tmp.end()) {
                    flag = false;
                    break;
                } else {
                    buf = buf.substr(0, buf.size()-1);
                }
            }
            if (flag) {
                return i;
            }
        }

        return ret;
    }
};
```