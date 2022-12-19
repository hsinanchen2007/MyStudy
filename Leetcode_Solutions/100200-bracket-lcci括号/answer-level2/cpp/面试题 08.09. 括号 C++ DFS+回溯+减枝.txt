### 解题思路
回溯 +DFS 
关键点 left<right时减枝，直接返回

### 代码

```cpp
class Solution {
public:
    vector<string> result;

    void dfs(string str, int left, int right, int n)
    {
        if (left > n || right > n) {
            return;
        }

        if (left == n && right == n) {
            result.push_back(str);
            return;
        }


        if (left < right) {
            return;
        }

        str.push_back('(');
        dfs(str, left + 1, right, n);
        str.pop_back();

        str.push_back(')');
        dfs(str, left, right + 1, n);
        str.pop_back();

        return;
    }

    vector<string> generateParenthesis(int n)
    {
        result.clear();
        string str;
        dfs(str, 0, 0, n);

        return result;
    }
};
```