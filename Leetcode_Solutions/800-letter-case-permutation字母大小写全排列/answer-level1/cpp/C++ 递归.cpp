### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution 
{
public:
    void func(int i, string S, vector<string> &res)
    {
        if(i!=S.size())
        {
            if(S[i]>='A' && S[i]<='Z') 
            {
                
                func(i+1,S,res);//对下一个字母进行大写->小写
                S[i]+=32;//大小写转换
                func(i+1,S,res);//转换后对下一个字母进行大写->小写
            }
            else if(S[i]>='a' && S[i]<='z') 
            {
                
                func(i+1,S,res);//对下一个字母进行小写->大写
                S[i]-=32;//大小写转换
                func(i+1,S,res);//转换后对下一个字母进行小写->大写
            }
            else
            {
                func(i+1,S,res);//如果非字母 就往下排查
            }
        }
        else
        {
            res.push_back(S); //结束 将转换后数字放入S
        }

    }
    vector<string> letterCasePermutation(string S)
    {
        vector<string> res;
        func(0,S,res);
        return res; 
    }
};
```