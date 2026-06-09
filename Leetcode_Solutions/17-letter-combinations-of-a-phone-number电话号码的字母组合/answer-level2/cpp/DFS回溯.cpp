### 解题思路
DFS遍历所有结果，回溯来还原上个状态，记得每次删除循环的最后一位

### 代码

```cpp
class Solution {
public:
    vector<string> alphabet = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string combination;
    vector<string> letterCombinations(string digits) {
        if(digits == "") return res;
        letter(digits, 0);
        return res;
    }

    void letter(string& digits, int depth){
        if(depth >= digits.length()){
            res.push_back(combination);
            return;
        }
        int p = digits[depth] - '2';
        for(int i = 0; i < alphabet[p].length(); ++i){
            combination += alphabet[p][i];
            letter(digits, depth+1);
            combination.pop_back();
        }
        return;
        
    }
};
```