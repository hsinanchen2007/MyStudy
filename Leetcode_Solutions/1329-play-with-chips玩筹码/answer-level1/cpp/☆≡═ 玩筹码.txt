1. 将第 i 个筹码向左或者右移动 2 个单位，代价为 0。这个条件使得移动筹码偶数个位置代价为0，把筹码分成了两类。
2. 可以把筹码无代价地移动到位置0和位置1。
3. 然后将两个位置筹码数少的返回。
```
class Solution {
public:
    int minCostToMoveChips(const vector<int>& chips) {
        unsigned odds = 0;
        unsigned evens = 0;
        for (const auto chip : chips)
            chip & 0x1 ? ++odds : ++evens;
        return min(odds, evens);
    }
};
```
