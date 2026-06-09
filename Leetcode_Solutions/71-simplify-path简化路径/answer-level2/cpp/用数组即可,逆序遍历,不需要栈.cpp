```
class Solution {
public:
    string simplifyPath(string &path) {
        for(int i=path.length(); i--; path[i]=(path[i]=='/'?' ':path[i]));
        stringstream istr(path);
        vector<string> vs;
        string str;
        for(; istr>>str;){
            if(str==".") continue;
            if(str!="..") vs.push_back(str);
            else if(vs.size()) vs.pop_back();
        }
        str.clear();
        for(int i=0; i<vs.size(); str.append("/"+vs[i++]));
        return str.length()?str:"/";
    }
};
```
