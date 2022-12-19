```c++
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people);
        int candies_give = 1, kids = 0;
        while (1) {
            if (candies_give > candies) {
                res[kids % num_people] += candies;
                break;
            } else {
                res[kids++ % num_people] += candies_give;
            }
            candies -= candies_give++;
        }
        return res;
    }
};
```