### 解题思路


### 代码

```cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        int hashSec[10] = {0}, hashGue[10] = {0};
        int a = 0, b = 0;
        for(int i = 0 ; i < secret.length() ; ++i)
        {
            if(secret[i] == guess[i])
                a++;
            else
            {
               hashSec[secret[i] - '0']++;
               hashGue[guess[i] - '0']++;
            }
        }
        for(int i = 0 ; i < guess.length() ; ++i)
        {
            if(hashSec[guess[i] - '0'] && hashGue[guess[i] - '0'])
            {
                hashSec[guess[i] - '0']--;
                hashGue[guess[i] - '0']--;
                b++;
            }
        }
        string ans = to_string(a) + "A" + to_string(b) + "B";
        return ans;
    }
};
```