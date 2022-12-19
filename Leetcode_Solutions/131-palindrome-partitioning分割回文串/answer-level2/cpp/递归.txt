```
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        lalala(s,0,{},ans);
        return ans;
    }

    bool isCircle(const string& s){
        int begin=0,end=s.size()-1;
        while(begin<end){
            if(s[begin]!=s[end]){
                return false;
            }
            ++begin;
            --end;
        }
        return true;
    }

    void lalala(const string& s, int pos, vector<string> temp, vector<vector<string>>& ans){
        if(pos==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=pos;i<s.size();++i){
            if(isCircle(s.substr(pos,i-pos+1))){
                temp.push_back(s.substr(pos,i-pos+1));
                lalala(s,i+1,temp,ans);
                temp.pop_back();
            }
        }
    }
};
```
