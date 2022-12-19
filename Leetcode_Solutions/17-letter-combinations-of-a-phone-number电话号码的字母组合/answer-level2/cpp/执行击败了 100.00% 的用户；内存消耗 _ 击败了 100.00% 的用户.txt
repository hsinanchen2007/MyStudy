### 解题思路
没啥好说的hash+DFS，这道题目也没有什么需要注意corner case

### 代码

```cpp
class Solution {
public:
    vector<string> table = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        func(res, "", digits, 0);
        return res;
    }

    void func(vector<string> &res, string str, string &digits, int i){
        if(i >= digits.size()){
            if(str.size() > 0) res.push_back(str);
            return;
        }else{
            string s = table[digits[i] - '2'];
            for(int j = 0; j < s.size(); ++j){
                str.push_back(s[j]);
                func(res, str, digits, i+1);
                str.pop_back();
            }
        }
    }
};
```

### 结果
执行用时 : 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户 
内存消耗 : 6.8 MB , 在所有 C++ 提交中击败了 100.00% 的用户