![image.png](https://pic.leetcode-cn.com/4885dc2ba56071262e21906fb0c90b5a634f35737e422b787eb7090defe20be1-image.png)



```
static auto pre =[] { std::ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr;}();

struct record {
    int begin = -1;
    int end = -1;
    int freq = 0;
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        for (int i = 0; i < nums.size() ; i++) {
            auto& record = records_[nums[i]];
            if (record.begin == -1) {
                record.begin = i;
            }
            record.end = i;
            record.freq++;
        }

        int max = 0;
        int result = 0;
        for (const auto& [num, record] : records_) {
            if (record.freq > max) {
                max = record.freq;
                result = record.end - record.begin + 1;
            } else if (record.freq == max) {
                auto temp = record.end - record.begin + 1;
                if (result > temp) {
                    result = temp;
                }
            }
        }
        return result;
    }
private:
    map<int, record> records_;
};
```
