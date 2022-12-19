### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> Candies_num(num_people);
        for(int index  = 0, dis_candies = 1; candies > 0; ++index){
            Candies_num[index % num_people] += (candies >= dis_candies) ? dis_candies : candies;
            candies -= dis_candies;
            ++dis_candies;
        }
        return Candies_num;
    }
};
```