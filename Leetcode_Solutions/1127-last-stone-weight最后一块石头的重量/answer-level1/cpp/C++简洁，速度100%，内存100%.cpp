```
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        while( stones.size()>1 ){
            if(stones[stones.size()-1]==stones[stones.size()-2]) {stones.erase(stones.begin()+stones.size()-2,stones.begin()+stones.size());}
            else {stones[stones.size()-1]=stones[stones.size()-1]-stones[stones.size()-2];stones.erase(stones.begin()+stones.size()-2);}
            sort(stones.begin(),stones.end());
        }
        if(stones.size()==1)return stones[0];
        else return 0;
    }
    
};
```
