### 解题思路

贪心：按字符出现频率降序排序

### 代码

```cpp
class Solution {
public:
    string reorganizeString(string S) {
        vector<pair<char, int>> vec;
        unordered_map<char, int> dict;
        int n = S.size();
        for(char c: S)
            dict[c]++;
        for(auto& p: dict)
            vec.push_back(p);
        sort(vec.begin(), vec.end(), [](auto& lhs, auto& rhs) -> bool {
            return lhs.second > rhs.second;
        });
        if(vec[0].second > (n + 1) / 2)        // 高频字符过半
            return "";
        S.clear();
        for(auto& p: vec) {
            string tmp(p.second, p.first);
            S.append(tmp);
        }
        //cout << S << endl;
        
        string res(n, '0');
        int i = 0;
        int j = 1;
        int last = 0;
        while(i < n && last < n) {
            res[i] = S[last++];
            i += 2;
        }
        while(j < n && last < n) {
            res[j] = S[last++];
            j += 2;
        }

        return res;
    }
};
```