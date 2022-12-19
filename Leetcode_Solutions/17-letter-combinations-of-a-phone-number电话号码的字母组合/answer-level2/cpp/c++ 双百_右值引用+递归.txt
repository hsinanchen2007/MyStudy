### 解题思路
如果拷贝字符串的话，将浪费大量时间，因此可以用右值引用

### 代码

```cpp
class Solution {
private:
    vector<string> res;   
    vector<string> table = {" ", "*", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        string s1 = "";
        digui(digits, std::move(s1), 0);
        return res;
    }
    void digui(string &digits, string &&temp, int index)
    {
        if(index == digits.size())
        {
             res.push_back(temp);
             return;
        }
        int num = digits[index] - '0';
        string s1 = table[num];
        for(int i = 0; i < s1.size(); i++)
            digui(digits, temp + s1[i], index + 1);
    }
};
```