### 解题思路
如出现重复字符，如abcb：1、交换ab后b acb 2、交换第二个b后b bca
会重复 所以在要写重复跳过 且for循环

### 代码

```cpp
class Solution {
public:
 vector<string> res;
    vector<string> permutation(string s) {
        //vector<string> res;
        if(s.size()==0) return res;
        dfs(s,0);
        return res;
    }
    void dfs(string& s,int begin)//s字符串，begin指向当前处理字符
    {
        if(begin>=s.size())
        {
            res.push_back(s);
            return;
        }
        for(int a=begin;a<s.size();a++)//为什么从begin开始
        {
            //加一个判断如果相等，不要交换
            if(judge(s,begin,a)) continue;
            swap(s[a],s[begin]);
            dfs(s,begin+1);
            swap(s[a],s[begin]);//回溯将bac还原成abc；下一步for()abc变成bca
        }
    }
        bool judge(string&s,int begin,int a)
        {
            for(int i=begin;i<a;i++)
            {if(s[i]==s[a]) return true;}
            
            return false;

        }
    
};
```