太low的做法

### 代码

```cpp
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() == 1) {
            return;
        }
        sort(nums.begin(), nums.end(), std::greater<int>());
        int low = 0;
        int high = nums.size()/2 == 0 ? nums.size() / 2 + 1 : nums.size() / 2;
        int swapx = 0;
        vector<int> nums2;
        for(int i = 0; i < nums.size(); ++i) {
            if(i % 2 != 0) {
                nums2.push_back(nums[low]);
                low++;
            } else {
                nums2.push_back(nums[high]);
                high++;
            }
        }
        nums = nums2;
    }
};
```