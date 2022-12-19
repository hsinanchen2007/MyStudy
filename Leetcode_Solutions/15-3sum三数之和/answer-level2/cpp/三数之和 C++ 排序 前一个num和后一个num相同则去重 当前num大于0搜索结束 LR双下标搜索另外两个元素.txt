### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target;
        vector<vector<int>> res;
        // 对给定区间所有元素排序，第三个参数没有则默认升序。
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // 去重，排序后，nums中的当前数字和上一个数字相同的话，进入下一个循环
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            // nums当前元素如果大于0，结束循环，不结束循环的话找到的也是重复的。
            if ((target = nums[i]) > 0) break;
            // l为nums数组当前元素的下一个元素下标，r为nums数组的最后一个元素下标
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] + target < 0) ++l;
                else if (nums[l] + nums[r] + target > 0) --r;
                else {
                    // 在res末尾添加元素
                    res.push_back({target, nums[l], nums[r]});
                    // 移动l、r，准备查找下一组合适的l、r
                    ++l, --r;
                    // 如果下标l、r的元素是前一个等于后一个，继续移动下标
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                }
            }
        }
        return res; 
    }
};


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int target;
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        if ((target = nums[i]) > 0) break;
        int l = i + 1, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] + nums[r] + target < 0) ++l;
            else if (nums[l] + nums[r] + target > 0) --r;
            else {
                res.push_back({target, nums[l], nums[r]});
                ++l, --r;
                while (l < r && nums[l] == nums[l - 1]) ++l;
                while (l < r && nums[r] == nums[r + 1]) --r;
            }
        }
    }
    return res; 
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(nums);
    for (int i=0; i<res.size(); i++) {
        vector<int> temp = res[i];
        for (int j=0; j<temp.size(); j++) {
            cout << temp[j] << ',';
        }
        cout << endl;
    }
}







```