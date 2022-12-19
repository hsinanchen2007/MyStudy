### 解题思路
放置右括号的条件: 左边未配对的左括号>=1

### 代码

```cpp
class Solution {
public:
    /*
     * 放置右括号的条件: 左边未配对的左括号>=1
     */
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str;
        GenParenthesis(n, n, str, result);
        return result;
    }

private:
    void GenParenthesis(int unusedLeft, int unusedRight, string ans, vector<string>& result) 
    {
        if (!unusedLeft && !unusedRight) {
            result.push_back(ans);
            return ;
        }
        if (unusedLeft > 0) {
            GenParenthesis(unusedLeft - 1, unusedRight, ans + "(", result);
        }
        if (unusedLeft < unusedRight) {
            GenParenthesis(unusedLeft, unusedRight - 1, ans + ")", result);
        }
    }

};
```