### 解题思路


### 代码

```cpp
class Solution {
public:
    int calculate(string s) {
        mp['+'] = mp['-'] = 1;
        mp['/'] = mp['*'] = 2;
        string ss = "";
        for(auto ch : s)
        {
            if(ch != ' ')
                ss += ch;
        }
        change(ss);
        return calc();
    }
    void change(string s)
    {
        node temp;
        for(int i = 0 ; i < s.length() ;)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                temp.num = 0;
                while(i < s.length() && s[i] >= '0' && s[i] <= '9')
                {
                    temp.num = temp.num * 10 + s[i] - '0';
                    i++;
                }
                temp.flag = true;
                q.push(temp);
            }
            else
            {
                temp.flag = false;
                while(!st.empty() && mp[s[i]] <= mp[st.top().op])
                {
                    q.push(st.top());
                    st.pop();
                }
                temp.op = s[i];
                st.push(temp);
                i++;
            }
        }
        while(!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
    }
    int calc(void)
    {
        node temp;
        while(!q.empty())
        {
            node f = q.front();
            q.pop();
            if(f.flag)
                st.push(f);
            else
            {
                temp.flag = false;
                long long num2 = st.top().num;
                st.pop();
                long long num1 = st.top().num;
                st.pop();
                char op = f.op;
                switch(op)
                {
                    case '+': temp.num = num1 + num2;
                    break;
                    case '-': temp.num = num1 - num2;
                    break;
                    case '*': temp.num = num1 * num2;
                    break;
                    case '/': temp.num = num1 / num2;
                }
                st.push(temp);
            }
        }
        return (int)st.top().num;
    }
private:
    unordered_map<char, int> mp;
    struct node{
        bool flag;
        long long num;
        char op;
    };
    stack<node> st;
    queue<node> q;
};
```