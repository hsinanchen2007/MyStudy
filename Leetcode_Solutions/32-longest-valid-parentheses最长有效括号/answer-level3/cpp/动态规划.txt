### 解题思路

注意处理边界

执行用时 :
8 ms
, 在所有 C++ 提交中击败了
67.56%
的用户
内存消耗 :
9.1 MB
, 在所有 C++ 提交中击败了
79.19%
的用户
### 代码

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        int n = s.size();
        vector<int> c(n+1);
        c[0] = 0;
        c[1] = 0;
        int tag_max = 0;
        for(int i = 2; i < n+1; i++){
            if(c[i-1] == 0 && s[i-1] == ')' && s[i-2] == '('){
                c[i] = c[i-2] + 1;
            }
            else if(c[i-1] != 0 && s[i-1] == ')' && i-2-c[i-1]*2 >=0 && s[i-2-c[i-1]*2] == '('){
                int tmp = i-2-c[i-1]*2;
                c[i] = c[i-1] + 1 + c[tmp];
            }
            else{
                c[i] = 0;
            }
            if(c[i] > tag_max){
                tag_max = c[i];
            }
        }
        return tag_max*2;
    }
};
```