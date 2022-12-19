回溯法
```cpp

class Solution {
private:
    vector<string> res;

    const string letterMap[10] = {" ", "", "abc", "def",
                                "ghi", "jkl", "mno",
                                "pqrs", "tuv", "wxyz"};

    // digits: 输入的数字字符串  
    // index: [0, index) 范围的digits已经处理，将处理第index索引处的字符
    // s: 已经找着的[0, index) 范围的一种字母组合
    // example： "234546"  index:3(指向5))  s:"adg"
    void findCombinations(const string &digits, int index, const string &s) {

        if (s.size() == digits.size()) { 
            res.push_back(s);
            return;
        }     

        string str = letterMap[digits[index] - '0']; //eg：取得key ’5‘ 对应的value “jkl”
        for (char c : str) {
            findCombinations(digits, index+1, s+c);
        }
    }

public:
    vector<string> letterCombinations(string digits) {  
        
        if (digits.size() == 0)
            return res;
        
        findCombinations(digits, 0, "");
        return res;
    }
};```