这个就是01背包问题，但是可以用bitset来巧妙解决

```
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<20001> bitSet;
        bitSet[0] = 1;
        int sum = 0;
        for (auto n : nums) {
            bitSet |= bitSet << n;
            sum += n;
        }
        if (sum % 2 != 0) {
            return false;
        }
        return bitSet[sum/2] == 1;
    }
};
```