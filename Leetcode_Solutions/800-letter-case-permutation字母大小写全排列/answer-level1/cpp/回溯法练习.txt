### 解题思路

- **二叉树的回溯法的模板**
- **编写一个包含if-else的func(i，n)函数进行递归**
- **if(i > n) 输出正解**
- **else{func(i+1,n); 转变大小写; func(i+1,n);}**
- **当为数字时直接进入func(i+1,n)**
- **ASCII码，A:65,Z:90,a:97,z:122**

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
                
                func(i+1,S,res);
                S[i]+=32;
                func(i+1,S,res);
            }
            else if(S[i]>='a' && S[i]<='z') 
            {
                
                func(i+1,S,res);
                S[i]-=32;
                func(i+1,S,res);
            }
            else
            {
                func(i+1,S,res);
            }
        }

        else
        {
            res.push_back(S);
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