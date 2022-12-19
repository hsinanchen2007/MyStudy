```
class Solution {
    vector<string> res;
    int len = 0;
    string ss;
public:
    void restore(string& s,int start,int r){
        for(int i = 1; i <= 3 && start+i <= len; ++i){
            if(i == 3){
                if(s[start] != '0' && stoi(s.substr(start,i)) <= 255){
                    ss.append(s.substr(start,i));
                    if(r == 1){
                        res.push_back(ss);
                    }
                    ss.push_back('.');
                    if(r > 1){
                        restore(s,start+3,r-1);
                    }
                    ss = ss.substr(0,ss.size()-4);
                }
            }
            else{
                if(i == 2 && s[start] == '0'){
                    continue;
                }
                if(len-start-i <= 3*(r-1)){
                    ss.append(s.substr(start,i));
                    if(r == 1){
                        res.push_back(ss);
                    }
                    ss.push_back('.');
                    if(r > 1){
                        restore(s,start+i,r-1);
                    }
                    ss = ss.substr(0,ss.size()-i-1);
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        len = s.size();
        if(len > 12){
            return res;
        }
        restore(s,0,4);
        return res;
    }
};
```
