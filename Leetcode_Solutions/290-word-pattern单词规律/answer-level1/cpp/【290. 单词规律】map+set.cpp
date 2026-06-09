### 思路
1. 分割单词，将单词存入vec中
2. 判断单词个数是否和模式串个数相等
3. 建立哈希映射，需要满足两个条件
   - 相同key，不能对应不同value
   - 不同key，不能对应相同value

### 代码

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> vec;
        stringstream ss(str);
        string tmp;
        while (ss >> tmp) {
            vec.push_back(tmp);
        }
        if (vec.size() != pattern.size()) return false;
        unordered_map<char, string> ump;
        set<string> st;//保存哈希表值个数，判断是否存在不同key对应相同value
        for (int i = 0; i < pattern.size(); ++i) {
            if (ump.count(pattern[i]) > 0) {
                if (ump[pattern[i]] != vec[i]) return false;
            }            
            ump[pattern[i]] = vec[i];
            st.insert(vec[i]);
        }
        if (st.size() != ump.size()) return false;
        return true;
    }
};
```