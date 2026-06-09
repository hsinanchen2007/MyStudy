![1.png](https://pic.leetcode-cn.com/697b3b397225545a830f589e2fc2b7ff4c9e3f7a73b8e52d58f3c3741d1d0297-1.png)

### 解题思路
先将比较特殊的情况单独处理（n==1和n==0），直接返回结果；
针对其他情况使用暴力求解的方法：
   暴力求解即：列出所有的可能情况，再将不合格的结果剔除。
   罗列所有的可能情况使用next_permutation()这个函数；注意：因为每个结果的第一个元素一定是‘(’，所以在重新排列时，第一个元素不参与；


### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n==0)
            return res;
        if(n==1)
        {
            res.push_back("()");
            return res;
        }
        string s = "";
        for(int i = 0 ;i < n;++i)
            s+="()";
        sort(s.begin(),s.end());
        do{
            if(IsLegal(s))
                res.push_back(s);
        }while(next_permutation(s.begin()+1,s.end()));
        return res;
    }
    bool IsLegal(string& s)
    {
        int count = 0;
        for(int i = 0;i < s.size();++i)
        {
            if(s[i]=='(')
                count++;
            else
                count--;
            if(count<0)
                return false;
        }
        return true;

    }
};
```