### 解题思路
最基本的DFS


### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        func(res, "", n, n);
        return res;
    }

    void func(vector<string> &res, string str, int l, int r){
        if(l == 0 && r == 0){
            res.push_back(str);
            return;
        }
        if(l > 0){
            func(res, str + '(', l-1, r);
        }
        if(r > 0 && r > l){
            func(res, str + ')', l, r-1);
        }
        return;
    }
};
```

### 结果
执行用时 : 4 ms , 在所有 C++ 提交中击败了 89.91% 的用户 
内存消耗 : 15.3 MB , 在所有 C++ 提交中击败了 59.60% 的用户