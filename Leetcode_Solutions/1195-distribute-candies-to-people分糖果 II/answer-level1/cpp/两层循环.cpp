### 解题思路
两层循环来处理，外层循环控制已分发糖果的数量，内层循环来分发糖果

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        if(num_people < 1)
            return vector<int>();
        vector<int> ans(num_people, 0);
        int k = 0, cir = 0;
        while(k < candies){
            for(int i = 0; i < num_people; ++i){
                k += i + 1 + cir * num_people;
                if(k < candies)
                    ans[i] += i + 1 + cir * num_people;
                else{
                    ans[i] += (candies - (k - (i + 1 + cir * num_people)));
                    break;
                }                    
            }
            ++cir;
        }
        return ans;
    }
};
```