```
class Solution {
public:
    string getHint(string secret, string guess) {
        int cntA = 0, cntB = 0;
        // 先找公牛
        for(int i=0; i<secret.length();i++)
        {
            if(secret[i] == guess[i])
            {
                cntA++;
                secret[i] = '*';
                guess[i] = '#';
            }
        }
        // 再找母牛
        for(int i=0; i<secret.length();i++)
        {
            int j = guess.find(secret[i]);
            if(j != guess.npos && guess[j] != '#')
            {
                cntB++;
                secret[i] = '*';
                guess[j] = '#';
            }
        }
        
        return to_string(cntA)+"A"+to_string(cntB)+"B";
    }
};
```