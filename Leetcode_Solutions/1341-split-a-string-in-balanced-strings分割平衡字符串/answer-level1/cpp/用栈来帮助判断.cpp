执行用时:4 ms,在所有 cpp 提交中击败了69.96%的用户;
内存消耗:8.4 MB,在所有 cpp 提交中击败了100.00%的用户.

这个题本身就比较简单，栈还是比较好的思想
```
class Solution {
public:
    int balancedStringSplit(string s) 
    {
        if(s.size()<=1) return 0;
        stack<char> tmp;
        int result=0;
        for (int i = 0; i < s.size(); i++)
        {
            if(tmp.empty())
            {
                result++;
                tmp.push(s[i]);
                continue;
            }
            char some = tmp.top();
            if((some=='L'&&s[i]=='R') || (some=='R'&&s[i]=='L'))//如果匹配上
                tmp.pop();//就删掉
            else
                tmp.push(s[i]);//否则就添加进来
        }
        return result;           
    }
};
```
