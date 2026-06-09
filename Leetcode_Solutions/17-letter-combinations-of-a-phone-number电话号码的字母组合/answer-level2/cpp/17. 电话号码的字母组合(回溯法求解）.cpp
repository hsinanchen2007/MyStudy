### 解题思路
首先根据题目要求存储数字和字符的映射信息，容易想到使用map来存储数字到字母的映射。
其次对于每一个数字都有对应的不同字符，那么每一步决策就用多种不同的方案，结果即要求存储所有的方案。
对于这类问题求一个方案的所有解容易想到使用回溯法求解所有的方案，对于每一种不同的数字有多种不同的决策方式，选择完一种方式后回溯时要回归原来的状态才能选择下一种决策。
当到达叶子节点时即得到一种决策方案，将结果加入到数组中。

### 代码

```cpp
class Solution {
public:
    map<char,string> M;
    vector<string> vec;
    string s;

    void init(map<char,string> &M)
    {
        M['2']="abc";
        M['3']="def";
        M['4']="ghi";
        M['5']="jkl";
        M['6']="mno";
        M['7']="pqrs";
        M['8']="tuv";
        M['9']="wxyz";
    }

    void dfs(string digits,int i)
    {
        if(i>=digits.length())
            vec.push_back(s);
        else
        {
            for(int j=0;j<M[digits[i]].length();j++)
            {
                string temp=s;
                s=s+M[digits[i]][j];
                dfs(digits,i+1);
                s=temp;
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
        {
            vector<string> v;
            return v;
        }
        init(M);
        dfs(digits,0);
        return vec;
    }
};
```