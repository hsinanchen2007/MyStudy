// 看题解里很多都是用 01 背包背 `sum // 2` 求解的，但是这题由于数据量不大，且是求恰好背满问题，直接上 bitset 就好了。😄

// ```c++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int ss = accumulate(nums.begin(), nums.end(), 0);
        if (ss % 2) {
            return false;
        }
        bitset<10005> bs(1);
        for (auto i: nums) {
            bs |= (bs << i);
            if (bs[ss / 2]) {
                return true;
            }
        }
        return false;
    }
};
// ```