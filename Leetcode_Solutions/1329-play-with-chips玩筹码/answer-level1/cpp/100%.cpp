```cpp
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int count=0;
        int chips_size=chips.size();
        for(int i=0;i<chips_size;++i){
            if(chips[i]%2==0)++count;
        }
        return count>chips_size-count?chips_size-count:count;
    }
};
```