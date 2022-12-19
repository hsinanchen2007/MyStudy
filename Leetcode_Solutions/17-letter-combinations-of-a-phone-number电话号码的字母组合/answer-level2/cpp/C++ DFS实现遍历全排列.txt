C++ DFS实现遍历全排列
![image.png](https://pic.leetcode-cn.com/3cfc84b7aba31aa17727ba2f71634fb19882d84c48805810a2246385f3fb395a-image.png)

```
class Solution {
    vector<string> charOptions;
    vector<string> res;
    int max = 0;
public:
    
    vector<string> letterCombinations(string digits) {
        max = digits.size();
        if (max == 0) return res;
        map<char, string> ref = { {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        for (auto ch : digits) {
            charOptions.emplace_back(ref[ch]);
        }
        for (auto ch : charOptions[0]) {
            string str;
            dfs(str + ch, 1);
        }
        return res;
    }
    
    void dfs(string str, int depth) {
        if (str.size() == max) res.emplace_back(str);
        if (depth > max - 1) return ;
        
        for (auto ch : charOptions[depth]) {
            dfs(str + ch, depth + 1);
        }
    }
};
```
