
![image.png](https://pic.leetcode-cn.com/859e8735f3e72e25bb1f6c44c8b28f2869b6165f9dc2fdaf0486546cef0eee44-image.png)

这是一个全排列的问题，需要针对代码细细体会。

难点在对于递归过程中每个解的处理，递归到最深处时，即获得解，递归返回的时候，需要删除之前的部分解。
需要删除的原因是：递归是在循环中，下一次循环到来的时候，需要重置解。
```
for (int i = 0; i < (int)s.size(); i++)
        {
            solver.push_back(letter_map[index][i]);
            allsequence(digits, letter_map, step + 1, solver);
            solver.erase(solver.end() - 1);
        }
```


```
class Solution {
public:
    vector<string> solvers;

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
        {
            return{};
        }

        vector<string> letter_map = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        string solver;

        allsequence(digits, letter_map, 0, solver);

        return solvers;
    }

    void allsequence(string &digits, vector<string> &letter_map, int step, string &solver)
    {
        if (step == digits.size())
        {
            solvers.push_back(solver);
            return;
        }

        int index = digits[step] - '0' - 2;
        string s = letter_map[index];
        for (int i = 0; i < (int)s.size(); i++)
        {
            solver.push_back(letter_map[index][i]);
            allsequence(digits, letter_map, step + 1, solver);
            solver.erase(solver.end() - 1);
        }
    }
};
```
