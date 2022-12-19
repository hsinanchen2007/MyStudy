
只用递归会超时，可见记忆数组提升很大
```c++
class Solution {
public:
    bool recur(size_t cur,string &s,vector<string>&vs,vector<bool>& visit){
        if(cur==s.size()) return true;
        if(!visit[cur]) return false;
        for(auto&p:vs){
            string tmp=s.substr(cur,p.size());
            if(tmp==p){
			    if (recur(cur+p.size(), s,vs, visit)) return true;
	    	}
        }
        visit[cur]=false;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> visit(s.size()+1,true);
        return recur(0,s,wordDict,visit);
    }
};
```