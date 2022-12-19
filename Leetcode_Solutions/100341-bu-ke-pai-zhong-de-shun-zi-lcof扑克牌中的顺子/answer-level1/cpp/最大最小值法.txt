### 解题思路
min = 14, max = 0为了找出最大最小值，坑。

### 代码

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int size = nums.size();
        int king = 0;
        int min = 14;
        int max = 0;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i< size; i++) {
            if(nums[i] == 0) {
                king++;
            } else {
                // 遇到前后重复的情况，直接返回false;
                if(i + 1 < size && nums[i] == nums[i+1]) {
                    return false;
                }
                
                min = std::min(min, nums[i]);
                max = std::max(max, nums[i]);
            }
        }
        int diff = max - min;
        cout << "king:" << king << " max:" << max << " min:"  << min << endl;

        if(king >= 0 && diff >= 2 && diff <= 4) {
            return true;
        } else {
            return false;
        }

        return false;
    }
};
```