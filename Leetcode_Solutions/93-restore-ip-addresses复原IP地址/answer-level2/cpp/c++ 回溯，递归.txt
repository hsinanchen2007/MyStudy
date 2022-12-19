```
class Solution {
    vector<string> res;
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> path;
        restoreIpAddresses(path,s,0);
        return move(res);
    }
    void restoreIpAddresses(vector<string> &path,string &s,int pos) {
        if(path.size()==4){
            if(pos>=s.size()){
                string tmp;
                for(auto &p:path)tmp.append(".").append(p);
                res.push_back(tmp.substr(1));
            };
            return;
        }
        if(pos<s.size()){
            path.push_back(s.substr(pos,1));
            restoreIpAddresses(path,s,pos+1);
            path.pop_back();
        }
        if(pos+1<s.size()&&s[pos]!='0'){
            path.push_back(s.substr(pos,2));
            restoreIpAddresses(path,s,pos+2);
            path.pop_back();
        }
        if(pos+2<s.size()&&(s[pos]-'0')*100+(s[pos+1]-'0')*10+(s[pos+2]-'0')<=255&&s[pos]!='0'){
            path.push_back(s.substr(pos,3));
            restoreIpAddresses(path,s,pos+3);
            path.pop_back();
        }
    }
};
```
