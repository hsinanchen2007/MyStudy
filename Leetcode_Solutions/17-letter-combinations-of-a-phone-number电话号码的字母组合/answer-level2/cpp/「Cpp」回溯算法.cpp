### 解题思路

原本想用map，但是想想也就9个数字，开个map可能不划算，直接用数组好了。相当于手工哈希了。

核心代码如下

```cpp
       string tmp = m[digits[pos] - '0'];
        for (int i = 0; i < tmp.size(); i++){
            s.push_back(tmp[i]);
            DFS(digits, pos+1, s, res, m);
            s.pop_back();
        }
```

每个数字对应这多个选择，每个选择都试一试，然后重置状态。


### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        vector<string> m = {
            "",
            "", "abc","def",
            "ghi","jkl","mno",
            "pqrs","tuv","wxyz"
        };

        vector<string> res;
        if (digits.size() == 0) return res;
        string s;

        DFS(digits, 0, s, res,m);
        return res;
    }

    void DFS(string digits, int pos, string & s, vector<string> &res, vector<string>& m){
        if (pos == digits.size()){
            res.push_back(s);
            return ;
        }
        //获取对应键盘的字母
        string tmp = m[digits[pos] - '0'];
        for (int i = 0; i < tmp.size(); i++){
            s.push_back(tmp[i]);
            DFS(digits, pos+1, s, res, m);
            s.pop_back();
        }
        return ;
    }
};
```