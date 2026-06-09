不需要剪枝的dfs回溯 + 一个容器保存键盘对应号映射即可。
套回溯基本框架就行，难度应该改成easy。
```
class Solution {
private:
    vector<string> res;
    vector<vector<char>> key = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'},
    };

    void dfs(const string& digits, string& tmp, int pos)
    {
        if (pos >= digits.size())
        {
            res.push_back(tmp);
            return ;
        }

        for (auto& it: key[digits[pos]-'2'])
        {
            tmp.push_back(it);
            dfs(digits, tmp, pos+1);

            tmp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) 
    {
        if (digits == "")   return {};

        string s;
        dfs(digits, s, 0);

        return res;
    }
};
```

![无标题.png](https://pic.leetcode-cn.com/b284730f52bde57a255b3373fcc568535c48f37197d422d05887c7f9deea32a5-%E6%97%A0%E6%A0%87%E9%A2%98.png)