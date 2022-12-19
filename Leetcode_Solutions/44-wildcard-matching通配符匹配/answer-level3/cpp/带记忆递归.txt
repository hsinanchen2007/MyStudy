```
class Solution {
public:
    bool isMatch(string s, string p) {
        map<pair<int,int>,bool> m;
        return lalala(s,p,0,0,m);
    }

    bool lalala(const string& s,const string& p,int ps,int pp,map<pair<int,int>,bool>& m){
        if(m.count({ps,pp})){
            return m[{ps,pp}];
        }
        if(ps==s.size()&&pp==p.size()){
            m[{ps,pp}]=true;
            return true;
        }
        if(pp==p.size()){
            m[{ps,pp}]=false;
            return false;
        }
        if(ps==s.size()){
            if(p[pp]!='*'){
                m[{ps,pp}]=false;
                return false;
            }
            m[{ps,pp}]=lalala(s,p,ps,pp+1,m);
            return m[{ps,pp}];
        }
        if(p[pp]!='?'&&p[pp]!='*'&&p[pp]!=s[ps]){
            m[{ps,pp}]=false;
            return false;
        }
        if(s[ps]==p[pp]||p[pp]=='?'){
            m[{ps,pp}]= lalala(s,p,ps+1,pp+1,m);
            return m[{ps,pp}];
        }
        if(p[pp]=='*'&&pp==p.size()-1){
            m[{ps,pp}]=true;
            return true;
        }
        if(p[pp]=='*'&&p[pp+1]=='*'){
            m[{ps,pp}]= lalala(s,p,ps,pp+1,m);
            return m[{ps,pp}];
        }
        if(p[pp]=='*'&&p[pp+1]=='?'){
            for(int i=ps;i<s.size();++i){
                if(lalala(s,p,i,pp+1,m)){
                    m[{ps,pp}]=true;
                    return true;
                }
            }
            m[{ps,pp}]=false;
            return false;
        }
        
        bool flag=lalala(s,p,ps,pp+1,m);
        if(flag){
            m[{ps,pp}]=true;
            return true;
        }
        for(int i=ps;i<s.size();++i){
            if(s[i]==p[pp+1]){
                if(lalala(s,p,i,pp+1,m)){
                    m[{ps,pp}]=true;
                    return true;
                }
            }
        }
        m[{ps,pp}]=false;
        return false;
        
    }
};
```
