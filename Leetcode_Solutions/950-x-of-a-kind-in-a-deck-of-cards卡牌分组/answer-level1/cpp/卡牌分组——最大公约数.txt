```C++ []
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int len = deck.size();
        map<int, int> times;
        for(int i=0; i<len; i++)
            times[deck[i]]++;
       
        int max_mul = times[deck[0]];
        for(int i=1; i<len; i++)
        {
            max_mul = gcd(max_mul, times[deck[i]]);
            if(max_mul == 1) return false;
        }

        max_mul = gcd(max_mul, len);
        return max_mul == 1 ? false:true;
    }
};
```

