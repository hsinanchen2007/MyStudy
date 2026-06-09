### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        // 数组v(i)表示下标为i时连续数组的最大和，用nums数组来初始化数组v
        vector<int> v(nums);
        int maxNum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            // 下标为i-1时连续数组的最大和加上当前nums[i]，如果比nums[i]大，则最大和的连续子数组在增大；如果比nums[i]小，则最大和的连续子数组从nums[i]开始，最大和变成nums[i]
            v[i] = max(v[i-1]+nums[i], nums[i]);
            if (maxNum < v[i]) {
                // 因为nums[i]有可能是负数，根v[i-1]相加后可能会变小。
                maxNum = v[i];
            }
        }
        return maxNum;
    }
};



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) {
    if(nums.empty()) return 0;
    vector<int> v(nums);
    int maxNum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        v[i] = max(v[i-1]+nums[i], nums[i]);
        if (maxNum < v[i]) {
            maxNum = v[i];
        }
    }
    return maxNum;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums) << endl;
}


```