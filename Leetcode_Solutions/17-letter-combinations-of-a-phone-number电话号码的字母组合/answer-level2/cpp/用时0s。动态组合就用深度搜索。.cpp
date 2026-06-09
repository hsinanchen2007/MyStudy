### 解题思路
此处撰写解题思路

![image.png](https://pic.leetcode-cn.com/4c33cc5df9aa32b9586f456453988c55135ff38b5c8ac6dda1c6ffbcac06447b-image.png)


### 代码

```cpp
class Solution {
public:
    Solution()
    {
        nrLetter['2']="abc";
        nrLetter['3']="def";
        nrLetter['4']="ghi";
        nrLetter['5']="jkl";
        nrLetter['6']="mno";
        nrLetter['7']="pqrs";
        nrLetter['8']="tuv";
        nrLetter['9']="wxyz";
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> res={};
        //以防万一，判断是否含有1.
        if(find(digits.begin(),digits.end(),'1') != digits.end()){
            return res;
        }
        string comb="";
        int k = 0;
        DFS(k, digits,res,comb);
        return res;
    }

    void DFS(int &k, string &digits, vector<string> &res, string comb)
    {   
        //以digits的大小为深度进行深度搜索（类似根据size的大小动态循环）
        if(k>digits.size()-1){
            res.emplace_back(comb);
            k--;
            return;
        }
        //以digit对应的字母为搜索方向，类似动态内层搜索。
        string letters = nrLetter[digits[k]];
        for(int i=0; i < letters.size(); i++){
            comb += letters[i];
            DFS(++k, digits,res,comb);
            comb.pop_back();
        }
        k--;
    }
    map<char,string> nrLetter;
};

```