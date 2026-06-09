class Solution {
public:
    vector<string> permutation(string S) {
        vector<string> ans;
        sort(S.begin(),S.end());
        string pre="";
        do{
            // if(pre==S) continue;
            // pre=S;
            ans.push_back(S);
        }while(next_permutation(S.begin(),S.end()));
        return ans;
    }
};