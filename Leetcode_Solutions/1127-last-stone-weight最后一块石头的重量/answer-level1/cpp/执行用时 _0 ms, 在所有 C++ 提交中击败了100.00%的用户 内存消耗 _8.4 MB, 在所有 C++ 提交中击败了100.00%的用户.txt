```
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(!stones.empty()){
            std::sort(stones.begin(),stones.end());
            int A = stones.back();
            stones.pop_back();
            if(stones.empty())
                return A;
            int B = stones.back();
            stones.pop_back();
            stones.push_back(A-B);
        }
        return 0;
    }
};
```
得亏想了半天，其实不用多想，直接干就行了，数据量这么小又不会超时