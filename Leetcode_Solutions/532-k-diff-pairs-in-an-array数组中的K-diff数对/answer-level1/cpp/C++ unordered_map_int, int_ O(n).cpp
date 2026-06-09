
```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        unordered_map<int, int> numTimes;  // 统计数字出现次数
        int ans = 0;

        for(int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            numTimes[num]++;
        }

        for(auto pair : numTimes) {
            int num = pair.first;   // 不妨假设数对的第一位小于等于第二位。这里遍历数组中存在的数，让该数为数对的第一位
            int times = pair.second;
            if(numTimes.count(num+k)) {  // 这里去查找数对的第二位是否存在。若存在，分条件讨论k
                if(k == 0 && numTimes[num] > 1)  ans += 1;
                if(k != 0) ans += 1;
            }
        }
        return ans;
    }
};
```
