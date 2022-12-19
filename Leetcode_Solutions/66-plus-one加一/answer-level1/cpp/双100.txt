class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int f=1;
        for(int i=digits.size()-1;i>=0;--i){
            if(digits[i]==9&&f==1){
                ans.push_back(0);
                continue;
            } else{
                ans.push_back(digits[i]+f);
                f=0;
            }
        }
        if(f==1) ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};