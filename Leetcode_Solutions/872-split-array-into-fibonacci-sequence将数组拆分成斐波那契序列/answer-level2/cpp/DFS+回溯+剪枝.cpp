### 解题思路

### 代码

```cpp
class Solution {
public:
    map<int, vector<vector<int>>> mem;
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ss;
        vector<vector<int>> vec = dfs(S, 0);
        for (vector<int> vecs : vec) {
            for (int i : vecs) {
                cout << i <<" ";
            }
            cout << endl;
        }
        for (int i = 0; i < vec.size(); i++) {
            int count = 0;
            if (vec[i].size() >= 3 ){
                for (int x : vec[i]) {
                    string str = to_string(x);
                    count += str.size();
                }
                if (count == S.size()) {
                    ss = vec[i];
                }
            }
        }
        return ss;
    }

    vector<vector<int>> dfs(string s, int index) {
        if (mem.find(index) != mem.end()) {
            return mem[index];
        }
        vector<vector<int>> vec;
        if (index >= s.size()) {
            return vec;
        }
        for (int i = index + 1; i <= s.size(); i++) {
            string str = s.substr(index, i-index);
            if (stoll(str) >= INT_MAX) {
                break;
            }
            if (str.size() >= 2 && str.front() == '0') {
                continue;
            }
            vector<vector<int>> vecResult = dfs(s, i);
            for (int j = 0; j < vecResult.size(); j++) {
                vector<int> vecTmp = vecResult[j];
                vecTmp.insert(vecTmp.begin(), stoi(str));
                if ((vecTmp.size() >= 3 && (long)vecTmp[0] + (long)vecTmp[1] == (long)vecTmp[2]) || vecTmp.size() < 3) {
                    vec.push_back(vecTmp);
                }
            }
            if (vecResult.empty()) {
                vector<int> v;
                v.push_back(stoi(str));
                vec.push_back(v);
            }
        }
        mem[index] = vec;
        return vec;
    }
};

```