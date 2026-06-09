```
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string res;
        int len=0;
        
        if(path[path.length()-1] != '/') path+= '/'; 
        for(int i=0; i<path.length(); i++)
        {
            if(path[i] == '/') 
            { 
                if(len != 0)
                {
                    string tmp = path.substr(i-len, len);
                    if(tmp == "."){}
                    else if(tmp == "..")
                    {
                        if(!s.empty()) s.pop();
                    }
                    else
                        s.push(tmp);
                }
                len = 0;
            }
            else len++;
        }
        if(s.empty()) return "/";
        while(!s.empty())
        {
            res =  '/' + s.top() + res;
            s.pop();
        }
        return res;
    }
};
```
