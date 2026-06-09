```
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int freq[128];
        int odd = 0;
        memset(&freq, 0, sizeof(freq));
        for(auto c:s)
        {
            freq[c]++;
        }
        for(int i=0; i<128; i++)
        {
            if(freq[i] % 2 == 1)
                odd++;
        }
        if(odd>1)
            return false;
        else
            return true;
    }
};
```
