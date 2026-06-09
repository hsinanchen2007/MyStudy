```
class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int min = 0x7ffffff;
        for(auto i:A)
        {
            if(i < min)
            min = i;
        }
        int sum = 0;
        while(min)
        {
            sum += min%10;
            min = min/10;
        }
        return sum%2==0?1:0;
    }
    
};
```