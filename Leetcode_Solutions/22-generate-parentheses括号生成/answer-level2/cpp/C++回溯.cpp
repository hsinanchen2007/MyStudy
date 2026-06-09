### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string cur_str="";
        backtrack(cur_str,n,0,0);
        return res;
    }

    void backtrack(string cur_str, int n, int left, int right)
    {
        if(right>left) return;
        if(left==n && right==n)
        {
            res.push_back(cur_str);
            return;
        }

        if(left<n)
        {
            backtrack(cur_str+"(",n,left+1,right);
        }
        if(right<n)
        {
            backtrack(cur_str+")",n,left,right+1);
        }
    }
};
```