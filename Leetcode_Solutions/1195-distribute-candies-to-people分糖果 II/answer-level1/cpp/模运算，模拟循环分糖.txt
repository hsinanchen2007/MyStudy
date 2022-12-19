不断地分糖，知道没有糖可分。

```
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        // 用模运算来重复分发，相当于将糖分给多组num_people，只需要叠加即可
        for(int i = 0; i % num_people < num_people; i++) {
            if(candies == 0) break;
            if(i + 1 < candies) {
                res[i % num_people] += i + 1;
                candies -= i + 1;
            }
            else {
                res[i % num_people] += candies;
                candies = 0;
            }
        }
        return res;
    }
};
```
