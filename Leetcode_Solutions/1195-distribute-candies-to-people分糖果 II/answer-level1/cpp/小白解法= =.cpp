### 解题思路
就是无脑解

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> num_candies(num_people);
        int cur_candies = 1;
        int cur_people = 0;
        while(candies > 0)
        {
            if(cur_people >= num_people)
                cur_people = 0;
            if(candies <= cur_candies)
            {
                num_candies[cur_people] += candies;
                candies = 0;
            }
            else
            {
                num_candies[cur_people] += cur_candies;
                candies -= cur_candies;
                ++cur_people;
                ++cur_candies;
            }
        }
        return num_candies;
    }
};
```