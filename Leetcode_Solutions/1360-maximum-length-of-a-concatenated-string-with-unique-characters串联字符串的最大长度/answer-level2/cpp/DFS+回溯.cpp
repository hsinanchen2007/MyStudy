### 解题思路
此处DFS+回溯，即可快乐搞定，DFS的深度即为arr的长度，广度即为 追加和不追加两种，所以利用DFS+回溯即可直接算出所有结果，然后遍历取出最大长度。
这次要注意首先需要剔除单个string中又重复字符的，然后在追加时需要进行判断，是否可以追加。

### 代码

```cpp
class Solution {
public:
    map<int, vector<string>> mem;
    int maxLength(vector<string>& arr) {
        vector<string> newArr;
        for (string s : arr) {
            if (OverLap(s)) {
                continue;
            }
            newArr.push_back(s);
        }

        vector<string> vecRes = dfs(newArr, 0);
        int maxLen = 0;
        for (string s : vecRes) {
            cout << s <<" ";
            maxLen = max(maxLen, (int)s.size());
        }
        return maxLen;
    }
    vector<string> dfs(vector<string>& arr, int index) {
        vector<string> vecResult;
        if (index == arr.size()) {
            vecResult.push_back("");
            return vecResult;
        }
        if (mem.find(index) != mem.end()) {
            return mem[index];
        }
        vector<string> vecPre = dfs(arr, index + 1);
        vecResult = vecPre;
        for (string str : vecPre) {
            if (IsIllegal(str, arr[index])) {
                vecResult.push_back(str+arr[index]);
            }
        }
        mem[index] = vecResult;
        return vecResult;
    }
    bool IsIllegal(string s1, string s2) {
        for (int i = 0; i < s1.size(); i++) {
            for (int j = 0; j < s2.size(); j++) {
                if (s1[i] == s2[j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool OverLap(string s) {
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};
```