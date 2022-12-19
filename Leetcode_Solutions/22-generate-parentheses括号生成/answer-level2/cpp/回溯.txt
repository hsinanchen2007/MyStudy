### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void back(vector<string>& ans, string& current,int open,int close,int n){
        if(current.size() == 2 * n){
            ans.push_back(current);
            return ;
        }
        if(open < n){
            current.push_back('(');
            back(ans,current,open + 1, close, n);
            current.pop_back();
        }
        if(close < open){
            current.push_back(')');
            back(ans,current,open, close + 1, n);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current;
        back(ans,current,0,0,n);
        return ans; 
    }
};
```