class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size()==0) {
            return 0;
        }
        if (stones.size()==1) {
            return stones[0];
        }
        sort(stones.begin(),stones.end());
        int len = stones.size();
        if (stones[len-1]==stones[len-2]) {
            stones.erase(stones.begin()+len-1);
            stones.erase(stones.begin()+len-2);
        } else {
            stones[len-2] = stones[len-1] - stones[len-2];
            stones.erase(stones.begin()+len-1);
        }
        return lastStoneWeight(stones);
    }
};