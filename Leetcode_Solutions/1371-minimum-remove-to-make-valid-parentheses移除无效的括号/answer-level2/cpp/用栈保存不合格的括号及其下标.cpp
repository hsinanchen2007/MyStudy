用stack<pair<char,int>>   来保存不合格的括号及其下标
遍历完后，用迭代器删除不合格的括号
```
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> stk;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ')')
            {
                if(stk.empty())
                    stk.push(make_pair(s[i],i));
                else if(stk.top().first == '(')
                {
                    stk.pop();
                }
                else
                {
                    stk.push(make_pair(s[i],i));
                }
            }
            else if(s[i] == '(' )
            {
                stk.push(make_pair(s[i],i));
            }
        }
        while(!stk.empty())
        {
            int index = stk.top().second;
            s.erase(s.begin()+index,s.begin()+index+1);
            stk.pop();
        }
        return s;
    }
};
```
