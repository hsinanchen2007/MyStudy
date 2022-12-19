```
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        map<int,int> count;
        for(auto t : time)
        {
            int a = t % 60, b = (60 - a) % 60;
            res += count[b];
            count[a] += 1;
        }
        return res;
    }
};

```