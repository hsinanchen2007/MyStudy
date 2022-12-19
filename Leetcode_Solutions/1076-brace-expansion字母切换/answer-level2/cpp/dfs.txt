```
class Solution {
public:
    bool dfs(vector<vector<string>> & prefix,int count,string  curr,vector<string> & res){
        if(count == prefix.size()){
            res.push_back(curr);
            return true;
        }
        for(int i = 0;i < prefix[count].size(); ++i){
            dfs(prefix,count+1,curr + prefix[count][i],res);
        }
        
        return true;
    }
    
    vector<string> split(string S){
        vector<string> res;
        string str(1,' ');
        int i = 0;
        int n = S.size();
        
        while(i < n ){
            if(S[i] >= 'a' && S[i] <= 'z'){
                str[0] = S[i];
                res.push_back(str);
            }
            ++i;
        }
        
        return res;
    }
    
    vector<string> expand(string S) {
        vector<vector<string>> covers;
        vector<string> ans;
        int n = S.size();
        int i = 0;
        
        while(i < n){
            if(S[i] == '{'){
                int l = i + 1;
                int r = 0;
                while(i < n && S[i] != '}'){
                    ++i;
                }
                r = i-1;
                covers.push_back(split(S.substr(l,r-l+1)));
            }else if(S[i] >= 'a' && S[i] <= 'z'){
                string str;
                str.push_back(S[i]);
                vector<string> t(1,str);
                covers.push_back(t);
                ++i;
            }else if(S[i] == '}'){
                ++i;
            }
        }
        dfs(covers,0,"",ans);
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};
```