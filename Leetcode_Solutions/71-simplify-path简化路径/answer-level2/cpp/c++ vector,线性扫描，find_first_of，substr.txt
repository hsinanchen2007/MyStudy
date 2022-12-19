```
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        for(int start=0;start!=string::npos;){
            auto end=path.find_first_of('/', start+1);
            auto name=path.substr(start,end-start);
            start=end;
            if(name=="/")continue;
            else if (name=="/.")continue;
            else if (name=="/.."){
                if(!v.empty())v.pop_back();
            }
            else v.push_back(name);
        }
        string res;
        for(auto &s:v){
            res+=s;
        }
        if(res.empty())return "/";
        return res;
    }
};
```
