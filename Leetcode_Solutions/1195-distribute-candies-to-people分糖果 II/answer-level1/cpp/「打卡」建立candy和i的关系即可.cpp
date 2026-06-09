```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ppl(num_people,0);
        // (candy - 1)%num_people = i，i代表当前分发的位置
        for(int candy=1;candies>0;candy++){
            if(candy < candies){
                ppl[(candy-1)%num_people] += candy;
            }else{
                ppl[(candy-1)%num_people] += candies;
            }
            candies -= candy;
        }
        return ppl; 
    }
};
```
