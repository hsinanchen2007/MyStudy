```
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size(), idx = 0;
        while(idx<len-1)
        {
            if(bits[idx] == 0) 
                idx+=1;
            else
                idx+=2;
        }
        return idx == len-1;
    }
};
```