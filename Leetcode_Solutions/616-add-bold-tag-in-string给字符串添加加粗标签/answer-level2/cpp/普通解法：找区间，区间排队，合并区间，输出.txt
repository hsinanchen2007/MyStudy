### 解题思路
找到匹配的区间，此处的坑是字符串中可能存在多个相同的 dict，为了保证所有的都能匹配上，此处找到第一个后还要检查是否有其他的。
把找到的区间按起始点进行排队，这样方便后续的区间合并
最后把重叠的区间合并，输出

### 代码

```cpp
bool comp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0]; 
}
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int size = dict.size();
        vector<vector<int>> d_section;
        vector<vector<int>> bold_section;
        
        if (size == 0)
            return s;
        
        for (int i = 0; i < size; i++) {
            int pos = 0;
again:
            string src = s.substr(pos);
            auto found = src.find(dict[i]);
            if (found != string::npos) {
                pos += found;
                vector<int> tmp(2);
                tmp[0] = pos;
                tmp[1] = pos + dict[i].size();
                d_section.push_back(tmp);
                if (tmp[1] != s.size()) {
                    pos += 1;
                    goto again;
                }
            }
        }
        
        if (d_section.empty())
            return s;
        
        /* merge sections */
        sort(d_section.begin(), d_section.end(), comp);
        bold_section.push_back(d_section[0]);
        for (int i = 1; i < d_section.size(); i++) {
            int j = 0;
            for (; j < bold_section.size(); j++) {
                if (d_section[i][0] <= bold_section[j][1]) {
                    if (d_section[i][1] > bold_section[j][1])
                        bold_section[j][1] = d_section[i][1];
                    break;
                }
            }
            if (j == bold_section.size())
                bold_section.push_back(d_section[i]);
        }
        
        string res;
        int pos = 0;
        for (auto &sec : bold_section) {
            res += s.substr(pos, sec[0] - pos);
            pos = sec[0];
            res += "<b>";
            res += s.substr(pos, sec[1] - pos);
            pos = sec[1];
            res += "</b>";
        }
        res += s.substr(pos, s.size() - pos);
        
        return res;
    }
};
```