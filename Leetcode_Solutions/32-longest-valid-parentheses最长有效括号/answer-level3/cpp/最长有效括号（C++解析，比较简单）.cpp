
基本思路：其实就是利用两个栈，一个用来存储括号，另外一个用来存储位置（这个位置代表合适的存储位置），然后把计算存储位置的最长连续长度即可，详细思路见源代码！
```
class Solution {
public:
    int longestValidParentheses(string s) 
    {
        stack<char> vec;
        stack<int> num;
        vector<int> pos;
        int maxlen=0;
        int len=0;
        if(s.size()<=1) return 0;
        for(int i=0;i<s.size();i++)
        {
            if(!vec.empty())
            {
                if(vec.top()=='('&&s[i]==')')
                {
                    pos.push_back(num.top());
                    pos.push_back(i);
                    //cout<<num.top()<<endl;
                    //cout<<i<<endl;
                    vec.pop();
                    num.pop();
                }
                else
                {
                    num.push(i);
                    vec.push(s[i]);
                }
            }
            else
            {
                num.push(i);
                vec.push(s[i]);
            }
        }
        sort(pos.begin(),pos.end());
        for(int i=0;i<pos.size();i++)
        {
            cout<<pos[i]<<endl;
            if(i!=0&&pos[i]-pos[i-1]==1)
            {
                len=len+1;
                maxlen=max(len,maxlen);
            }
            else
            {
                len=1;
            }
        }
        return maxlen;
    }
};
```
