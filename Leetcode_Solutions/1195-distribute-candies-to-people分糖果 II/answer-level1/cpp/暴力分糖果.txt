```C++ []
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int i=0;
        while(candies>0)
        {
            res[i % num_people] = res[i% num_people] + min(candies, i+1);
            candies = candies - min(candies, i+1);
            i++;
        }
        return res;
    }
```

