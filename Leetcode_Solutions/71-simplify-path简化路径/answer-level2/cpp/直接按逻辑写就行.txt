```
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        string temp="";
        for(int i=0;i<path.size();++i){
            if(path[i]!='/'){
                temp+=path[i];
            }
            if(path[i]=='/'||i==path.size()-1){
                if(temp!=""){
                    if(temp=="."){
                        temp="";
                    }
                    else if(temp==".."){
                        temp="";
                        if(!v.empty())
                            v.pop_back();
                    }
                    else{
                        v.push_back(temp);
                    }
                }
                temp="";
            }
        }
        string ans;
        for(auto a:v){
            ans+='/'+a;
        }
        return v.empty()?"/":ans;
    }
};
```
