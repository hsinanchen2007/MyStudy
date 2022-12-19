```
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int len = A.size();
        vector<int> dp(len);

        dp[0] = A[0];
        for(int i = 1; i < len; i++){
            dp[i] = dp[i - 1] + A[i];
        }
        
        if(dp[len - 1] % 3 != 0){
            return false;
        }

        int i = 0, j = len - 2;

        while(i < j && dp[i] != dp[len - 1] / 3){
            i++;
        }
        while(j > i && (dp[len - 1] - dp[j]) != dp[len - 1] / 3){
            j--;
        }

        if(i < j){
            return true;
        }

        return false;
    }
};
```
