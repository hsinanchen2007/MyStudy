```
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0)
            return true;
        
        int sum = 0;
        int maxbits = 0;
        for (int i = maxChoosableInteger; i >= 1 && sum < desiredTotal; i--) {
            sum += i;
            maxbits += (1 << (i - 1));
        }
        if (sum < desiredTotal)
            return false;
        
        vector<bool> dp0(maxbits + 1);
        vector<bool> dp1(maxbits + 1);
        for (int i = maxbits; i >= 0; i--) {
            int s = 0;
            for (int k = 1; k <= maxChoosableInteger; k++)
                if ((1 << (k - 1)) & i)
                    s += k;
            
            if (s >= desiredTotal) {
                dp0[i] = false;
                dp1[i] = true;
            } else {
                dp0[i] = false;
                dp1[i] = true;
                for (int j = 1; j <= maxChoosableInteger; j++) {
                    if ((1 << (j - 1)) & i)
                        continue;
                    
                    if (dp1[i] && ((s + j >= desiredTotal) || !dp0[((1 << (j - 1)) | i)]))
                        dp1[i] = false;
                    
                    if (!dp0[i] && ((s + j >= desiredTotal) || dp1[((1 << (j - 1)) | i)]))
                        dp0[i] = true;
                    
                    if (dp0[i] && !dp1[i])
                        break;
                }
            }
        }
        return dp0[0];
    }
};
```
