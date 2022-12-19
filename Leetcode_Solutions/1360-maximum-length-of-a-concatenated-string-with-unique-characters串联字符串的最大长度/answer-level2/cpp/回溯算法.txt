### 解题思路

对于每个单词，有扩展/不扩展两种选择，分别进行dfs。

### 代码

```cpp
class Solution {
private:
    string maxStr;
public:
    int maxLength(vector<string>& arr) {
        string cur = "";
        int res = dfs(arr, cur, 0);
        cout << maxStr << endl;
        return res;
    }
    
    int dfs(vector<string>& arr, string cur, int i) {
        int n = arr.size();
        if(i == n) {
            if(cur.size() > maxStr.size())
                maxStr = cur;
            return cur.size();
        }
        int add, notAdd;
        notAdd = dfs(arr, cur, i+1);
        string expandStr = cur.append(arr[i]);  // 字符串的连接顺序无关紧要
        if(isValid(expandStr)) {
            add = dfs(arr, expandStr, i+1);
            return max(add, notAdd);
        }
        return notAdd;
    }
    
    bool isValid(string& a) {
        vector<int> dict(26, 0);
        for(char& c: a) {
            dict[c - 'a']++;
            if(dict[c - 'a'] > 1)
                return false;
        }
        return true;
    }
};
```