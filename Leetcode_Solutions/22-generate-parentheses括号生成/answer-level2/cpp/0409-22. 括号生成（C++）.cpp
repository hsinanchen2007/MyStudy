### 解题思路
组合问题、回溯算法

### 代码

```cpp
class Solution {
public:
    void generateParenthesis(int n, int m,int max ,vector<string>& res,string str){
        if( n == max && m == max) {
            res.push_back(str);
            return;
        }
        if (n < max) {
            str += "(";
            generateParenthesis(n + 1,m, max,res,str);
            str.pop_back();
        }
        if (m < n){
            str += ")";
            generateParenthesis(n,m + 1, max,res,str);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesis(0,0, n,res,"");
        return res;
    }
};

```