### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people,0);
        int share = 1;
        while(candies){
            for(int i = 0;i<num_people;i++){
                if(candies-share>=0){
                    ans[i] += share;
                    candies -= share;
                    share++;
                }
                else{
                    ans[i] += candies;
                    candies = 0;

                }
                
            }

        }
        return ans;
    }
};
```