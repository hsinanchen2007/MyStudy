### 解题思路
双指针，数组排序。
转换为2数之和（range[i+1,size),target = 0 - num[i])。
从左向右扫，路过重复节点。
从右向左扫，只要满足就添加（多个解）。

### 代码

```cpp

class Solution {
public:
    void addNoDup(vector<int> ans, vector<vector<int>>& result)
    {
        result.push_back(ans);
    }
    void twoSum(vector<int>& nums, int start, int target, vector<vector<int>>& result)
    {
        int left = start, right = nums.size() - 1;
        int prevLeft = INT_MIN;
        while (left < right) {
            int cl = nums[left];
            if (cl == prevLeft) {
                left++;
                continue;
            }
            int expect = target - cl;
            while (nums[right] > expect && right > left) {
                right--;
            }
            if (nums[right] == expect && left < right) {
                prevLeft = cl;
                addNoDup({nums[start - 1], nums[left], nums[right]}, result);
                right--;
            }
            left++;
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> result;
        int len = nums.size();

        sort(nums.begin(), nums.end());
        int prev = INT_MIN;
        for (int i = 0; i < len - 2; i++) {
            if (nums[i] != prev) {
                twoSum(nums, i + 1, 0 - nums[i], result);
                prev = nums[i];
            }
        }
        return result;
    }
};
```