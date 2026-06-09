```
class Solution {
public:
    vector<vector<bool>> v;
    vector<vector<string>> ret;
    vector<string> tp;
    string s;
    int s_l;
    
    void helper(int idx){
        if(idx == s_l){
            ret.push_back(tp);
            return;
        }
        
        for(int i=idx;i<s_l;i++){
            if(this -> v[idx][i]){
                string st = this -> s.substr(idx,i-idx+1);
                tp.push_back(st);
                helper(i+1);
                tp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        this -> s_l = s.size();
        this -> v.resize(s_l,vector<bool>(s_l,false));
        for(int i=s_l-1;i>=0;i--){
            for(int j=i;j<s_l;j++){
                if(i == j){
                    this -> v[i][j] = true;   
                }else if(j - i == 1){
                    if(s[i] == s[j])
                        this -> v[i][j] = true;
                }else{
                    if(s[i] == s[j] && v[i+1][j-1])
                        this -> v[i][j] = true;
                }
            }
        }
        
        this -> s = s;
        helper(0);
        return ret;
    }
};
```
