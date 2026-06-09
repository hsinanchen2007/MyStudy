```C++ []
class Solution {
public:
    void backtrack(vector<vector<int>>& ans, int n, int k, vector<int>& curr, int start){
        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }
        
        for(int i = start; i < n + 1; i++){
            curr.push_back(i);
            backtrack(ans, n, k, curr, i + 1);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        
        backtrack(ans, n, k, curr, 1);
        return ans;
    }
};

```