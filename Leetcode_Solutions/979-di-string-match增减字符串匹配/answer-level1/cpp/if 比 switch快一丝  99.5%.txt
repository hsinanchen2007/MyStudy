class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ans;
        int right = S.length();
        int left = 0;
        for(int i = 0; i < S.length(); i++){
           if(S[i] == 'I'){
                ans.push_back(left++);

            }
            else{
                ans.push_back(right--);
            }

        }
        
        ans.push_back(left);

        return ans;
    }
};