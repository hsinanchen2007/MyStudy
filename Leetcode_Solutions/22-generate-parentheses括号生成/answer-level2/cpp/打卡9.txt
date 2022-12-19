### 解题思路
 思路是这样的，前x个构成的括号，和n-x构成的括号进行组合。这样就能组合成所有的情况了。

### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0)return {""};
        vector<string> r;
        for(int i = 0 ; i < n ; i++){
            for(auto y : generateParenthesis(i)){
                for(auto x : generateParenthesis(n - 1 - i)){
                    r.push_back("(" + x + ")" + y);
                }
            } 
        }
        
        return r;
    }
};
```