```
class Solution {
public:
    //1. 用map记录每个数字按键对应的所有字母
    map<char, string> M = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    //2. 存储最终结果和临时结果的变量
    vector<string> ans;
    string current;

    //3. DFS函数，index是生成临时结果字串的下标，
    //每一个digit[index]数字对应临时结果current[index]的一位字母
    void DFS(int index, string digits) {
        //出口
        if(index == digits.size()) {
            ans.push_back(current);
            return;
        }
        //递归调用
        //对于当前输入的第index号数字(digits[index])，
        //枚举其对应的所有字母(M[digits[index]][i])
        for(int i = 0; i < M[digits[index]].size(); i++) {
            current.push_back(M[digits[index]][i]);     //临时结果压入一个字母
            DFS(index + 1, digits);             //以压入该字母这一“情况”为前提，构造此“分支”的后续结果
            current.pop_back();                 //状态还原，例如临时结果从 "ab" -> "a"，下一次循环尝试"ac" 
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return ans;
        }
        DFS(0, digits);
        return ans;
    }

};
```
