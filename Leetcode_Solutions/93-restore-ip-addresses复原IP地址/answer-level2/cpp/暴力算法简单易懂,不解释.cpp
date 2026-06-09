```
class Solution {
public: //考验我对字符串的掌握了
    bool isOk(string s){
        if(s.size()>1&&s[0]=='0') return false;
        int x;
        stringstream sstr(s);
        sstr >> x;
        if(x<0||x>255) return false;
        else  return true;
    }
    vector<string> restoreIpAddresses(string s) {
        int len = s.size();
        vector<string> ret;
        if(len>12) return ret;
        string a,b,c,d;
        for(int i=1;i<len-2;i++)
            for(int j=i+1;j<len-1;j++)
                for(int k=j+1;k<len;k++){
                    a=s.substr(0,i);
                    if(!isOk(a)) continue;
                    b=s.substr(i,j-i);
                    if(!isOk(b)) continue;
                    c=s.substr(j,k-j);
                    if(!isOk(c)) continue;
                    d=s.substr(k,len-k);
                    if(!isOk(d)) continue;
                    ret.push_back(a+'.'+b+'.'+c+'.'+d);
                }
        return ret;
    }
};
```
