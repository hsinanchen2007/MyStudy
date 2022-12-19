### 解题思路
字典树

### 代码
字典树
```cpp
const static int __ = [](){ 
  ios::sync_with_stdio(false); 
  cin.tie(NULL); 
//   cout.tie(NULL); 
  return 0;  
}();

struct Node {
    int next[26] = {0};
    int index = -1;
};
class Solution {
private:
    Node tie[100002];
    int N = 1;
public:
    vector<vector<int>> multiSearch(const string& big, vector<string>& smalls) {
        int lenS = smalls.size();
        vector<vector<int>> res(lenS);
        if (lenS == 0)
            return res;
        int i = 0;
        for (auto small : smalls) {
            insert(small, i);
            i++;
        }
        int len = big.size();
        for (int i = 0; i < len; ++i) {
            search(big, res, i);
        }
        return res;
    }
    void insert(const string& small, const int& i) {
        int cnt = 0;//注意初始值，调了好半天
        for (const char& c : small) {
            if (tie[cnt].next[c - 'a'] == 0) {
                tie[cnt].next[c - 'a'] = N++;
            } 
            cnt = tie[cnt].next[c - 'a'];
        }
        tie[cnt].index = i;
    }

    void search(const string& big, vector<vector<int>>& res, const int& pos) {
        int lenB = big.size();
        string str = big.substr(pos, lenB - pos);
        int cnt = 0;//注意初始值，调了好半天
        int len = str.size();
        for (int i = 0; i < len; i++) {
            if(tie[cnt].next[str[i] - 'a'] == 0)
                return;
            cnt = tie[cnt].next[str[i] - 'a'];
            if (tie[cnt].index != -1) {
                res[tie[cnt].index].push_back(pos);
            }
        }
    }
};
```
**map调用**
```
const static int x = [](){ 
  ios::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL); 
  return 0;  
}();
class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        int lenS = smalls.size();
        vector<vector<int>> res(lenS);
        if (lenS == 0)
            return res;
        unordered_map<string, int> hash;
        int i = 0;
        for (auto small : smalls) {
            hash.insert({small, i++});
        }
        int len = big.size();
        for (int i = 0; i < len; ++i) {
            for(int j = i + 1; j <= len; j++) {
                string str = big.substr(i, j - i);
                if (hash.find(str) != hash.end()) {
                    res[hash[str]].emplace_back(i);
                }
            }
        }
        return res;
    }

};
```

递归
```
class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        vector<vector<int>> res;
        if (smalls.size() == 0)
            return res;
        for (auto small : smalls) {
            vector<int> tmp;
            find(big, small, tmp, 0);
            res.emplace_back(move(tmp));
        }
        return res;
    }

    void find(const string& big, const string& small, vector<int>& res, int start) {
        int lenS = small.size();
        int lenB = big.size();
        if (lenS == 0)
            return;
        auto pos = big.find(small);
        if (pos != big.npos) {
            res.push_back(pos + start);
            string tmp = big.substr(pos + 1, lenB - pos - 1);
            find(tmp, small, res, start + pos + 1);
        }
    }
};
```

