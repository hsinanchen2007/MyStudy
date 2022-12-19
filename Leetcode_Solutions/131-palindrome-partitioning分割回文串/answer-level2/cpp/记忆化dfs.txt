```
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
        vector<vector<string>> ans;
        vector<string> res;
        dfs(s, 0, memo, res, ans);
        return ans;
    }
    int is_palindrome(string& s, int start , int end){
        while(start <= end){
            if(s[start] != s[end]) return 0;
            start++;
            end--;
        }
        return 1;
    }
    void dfs(string& s, int start, vector<vector<int>>& memo, vector<string>& res, vector<vector<string>>& ans){
        if(start >= s.size()){    
            ans.push_back(res);
            return ;
        }
        for(int i = start + 1; i <= s.size(); i++)
        {
            if(memo[start][i - 1] == -1) memo[start][i - 1] = is_palindrome(s, start, i - 1);
            if(memo[start][i - 1] == 1){
                res.push_back(s.substr(start, i - start));
                dfs(s, i, memo, res, ans);
                res.pop_back();
            }
        }
    }
};```