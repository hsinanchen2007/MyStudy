```
class Solution {
public:
    bool isPalindrome(string& s,int beg,int end){
        while(beg<end){
            if(s[beg]!=s[end]) return false;
            beg++;
            end--;
        }
        return true;
    }
    void backtrack(string& s,int splitPos,vector<string>& splitstr,vector<vector<string>>& res){
        if(splitPos==s.length()){
            res.emplace_back(splitstr);
            return ;
        }
        for(int i=splitPos;i<s.length();i++){
            if(isPalindrome(s,splitPos,i)){
                splitstr.push_back(s.substr(splitPos,i+1-splitPos));
                backtrack(s,i+1,splitstr,res);
                splitstr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {//回溯算法
        vector<vector<string>> res;
        vector<string> splitstr;
        backtrack(s,0,splitstr,res);
        return res;
    }
};
```
