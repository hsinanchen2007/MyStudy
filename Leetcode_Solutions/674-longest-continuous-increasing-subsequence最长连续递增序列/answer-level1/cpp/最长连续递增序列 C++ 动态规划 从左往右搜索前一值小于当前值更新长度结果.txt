### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    // O(1) 动态规划
    int findLengthOfLCIS(vector<int>& nums) {
        // 输入数组为空return长度0
        if (nums.empty()) return 0;
        // res保存结果，count保存当次长度
        int res = 1, count = 1;        
        // 从左往右搜索
        for (int i = 1; i < nums.size(); i++) {
            // 如果前一个值小于当前值，当次长度加1，更新结果
            if (nums[i - 1] < nums[i]) {
                count++;
                res = max(res, count);
            } else count = 1;
        }
        return res;
    }
};


#include <iostream>
#include <vector>

using namespace std;

int findLengthOfLCIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    int res = 1, count = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i - 1] < nums[i]) {
            count++;
            res = max(res, count);
        } else count = 1;
    }
    return res;
}

int main() {
    vector<int> nums = {1,3,5,4,7};
    cout << findLengthOfLCIS(nums) << endl;
}



```