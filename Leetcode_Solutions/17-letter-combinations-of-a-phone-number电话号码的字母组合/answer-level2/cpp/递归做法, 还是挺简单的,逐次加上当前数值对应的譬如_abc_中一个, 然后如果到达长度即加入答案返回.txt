### 解题思路
还是挺简单的,逐次加上当前数值对应的譬如"abc"中一个, 然后如果到达长度即加入答案返回, 如果达不到长度继续递归下去

### 代码

```cpp
class Solution {
public:
    // 不是一个简单的题目,可能要用到
    void  traverse(const string& digits, string word, size_t pos, vector<string>& res)
    {
        if (pos == digits.length())
        {
            res.emplace_back(word);
            return;
        }
        
        auto newWordIndex = digits[pos] - '0';
        for (int i = 0; i < mapping[newWordIndex].length(); ++i)
        {
            traverse(digits, word + mapping[newWordIndex][i], pos+1, res);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0) return res;

        traverse(digits, "", 0, res);
        return res;
    }

private:
    std::vector<string> mapping{" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};
```