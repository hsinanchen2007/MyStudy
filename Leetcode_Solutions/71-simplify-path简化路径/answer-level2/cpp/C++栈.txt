执行用时 : 4 ms , 在所有 C++ 提交中击败了 99.37% 的用户 内存消耗 : 9.5 MB , 在所有 C++ 提交中击败了 98.26% 的用户

主要是分为/ . 和其他三类来处理，直接上代码
```
class Solution {
public:
    string simplifyPath(string path) {
        stack<char> s;
        string str = "";
        if(path[path.length()-1] != '/')
            path = path + '/';
        for(int i=0; i<path.length(); i++)
        {
            if(path[i] == '/')
            {
                if(s.empty() || (s.top() != '/' && s.top() != '.'))
                {
                    s.push(path[i]);
                }
                else if(!s.empty() && s.top() == '.')
                {
                    s.pop();
                }
            }
            else if(!s.empty() && (path[i] != '/') && path[i] != '.')
            {
                s.push(path[i]);
            }
            else if(!s.empty() && path[i] == '.')
            {
                if(s.top() == '/')
                {
                    s.push('.');
                }
                else if(s.top() == '.' && (path[i+1] == '/'))
                {
                    s.pop();
                    if(s.top() == '.' || s.top() != '/')
                    {
                        s.push('.');
                        s.push('.');
                        s.push('.');
                        continue;
                    }
                    if(s.size() > 1)
                    {
                        s.pop();
                        while(!s.empty() && s.top() != '/')
                        {
                            s.pop();
                        }
                    }
                }
                else
                {
                    s.push('.');
                }
            }
            else
                continue;
        }            
        if((s.top() == '/') && (s.size()>1))
        {
            s.pop();
        }
        while(!s.empty())
        {
            str += s.top();
            s.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
```