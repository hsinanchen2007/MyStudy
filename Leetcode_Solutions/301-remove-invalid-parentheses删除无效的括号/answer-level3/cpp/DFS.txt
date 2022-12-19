### 解题思路
这里通过DFS来进行迭代：
1、先求出所有需要删除的左括弧和右括弧数量；
2、然后通过for循环，DFS所有能被去掉的括弧组合；
3、去重再判断合法性；
4、返回

### 代码

```cpp
class Solution {
public:
    set<string> setResult;
    int removeMax = INT_MAX;
    vector<string> removeInvalidParentheses(string s) {
        int left = 0;
        int right = 0;
        for (char c : s) {
            if (c == '(') {
                left++;
            }
            if (c == ')') {
                if (left > 0) {
                    left --;
                } else {
                    right ++;
                }
            }
        }

        dfs (s, 0, left, right);
        vector<string> vecResult(setResult.begin(), setResult.end());
        return vecResult;
    }

    void dfs(string s, int index, int left, int right) {
        if (left == 0 && right == 0) {
            if (isOk(s)) {
                setResult.insert(s);
            }
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (left > 0 && s[i] =='(') {
                dfs(s.substr(0,i)+s.substr(i+1), i, left - 1, right);
            }
            if (right > 0 && s[i] ==')') {
                dfs(s.substr(0,i) + s.substr(i+1), i, left, right - 1);
            }
        }
    }
    bool isOk(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count ++;
            }
            if (c == ')') {
                count --;
                if (count < 0) {
                    return false;
                }
            }
        }
        return true;
    }
};
```