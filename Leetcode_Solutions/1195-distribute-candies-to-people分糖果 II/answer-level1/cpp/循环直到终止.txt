
```
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people,0);
        int i = 1,k=0;
        while(candies >= i) {
            result[(k++)%(num_people)] += i;
            candies -= i;
            i++;
        }
        result[k%num_people] += candies;
        return result;
    }
};
```
