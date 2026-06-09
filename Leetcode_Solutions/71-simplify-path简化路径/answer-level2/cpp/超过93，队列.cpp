
```c++ []
class Solution {
public:
    string simplifyPath(string path) {
        string result;
        vector<string> que;
        for(int i = 0; i < path.size(); i++)
        {
            string temp;
            while(path[i] != '/' && i < path.size())
            {
                temp += path[i++];
            }
            if(temp == ".")
                continue;
            else if(temp == "..")
            {
                if(que.empty())
                    continue;
                que.pop_back();
                continue;
            }
            else if(temp.size() != 0)
                que.push_back(temp);
        }
        for(int i = 0; i < que.size(); i++)
        {
            result += '/';
            result.append(que[i]);
        }
        if(result.size()==0)return "/";
        return result;
    }
};
```
