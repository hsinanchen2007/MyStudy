还是要自信＋沉着，深入思考

```
class Solution {
public:
    vector<vector<string>> ans;
    string s;
    bool ischeck(int i,int r){
        while(i<r && s[i] == s[r]){
            i++;r--;
        } 
        return i>=r;
    }
    void dfs(int start, vector<string>&tmp){
        if(start >= s.length()){
            ans.push_back(tmp);
        }
        for(int i=start;i<s.length();i++){
            if(ischeck(start, i)){
                tmp.push_back(s.substr(start,i - start + 1));
                dfs(i+1,tmp);
                tmp.pop_back();

            }
        }
    }

    vector<vector<string>> partition(string s) {
        this->s = s;
        vector<string> tmp;
        dfs(0, tmp);
        return ans;
    }
};
```
