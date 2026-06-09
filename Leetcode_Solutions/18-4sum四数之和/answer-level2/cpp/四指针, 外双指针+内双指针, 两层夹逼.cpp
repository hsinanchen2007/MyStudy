四指针, 外双指针+内双指针, 两层夹逼原理, 根据最大和和最小和跳过不必要的运算判断, 减枝

```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 4) {
            return {};
        }
        vector<vector<int>> rst;

        sort(nums.begin(), nums.end());

        int begin = 0;  // 外左指针, 赋起始值
        int end = len - 1;  // 外右指针, 赋起始值
        while (begin <= len - 4) {
            end = len - 1;  // 外右指针每次初始为最右端
            if (begin >= 1 && nums[begin] == nums[begin - 1]) {
                begin++;  // 重复值, 跳过
                continue;
            }

            while (end - begin >= 3) {
                if (end <= len - 2 && nums[end] == nums[end + 1]) {
                    end--;   // 重复值, 跳过
                    continue;
                }

                int left = begin + 1;  // 内左指针, 赋起始值
                int right = end - 1;   // 内右指针, 赋起始值
                int curMaxSum = nums[begin] + nums[right - 1] + nums[right] + nums[end];
                if (curMaxSum < target) {
                    break;  // 当前最大和比目标和小, 没必要左移end了, 直接break, 需要begin++;
                }
                int curMinSum = nums[begin] + nums[left] + nums[left + 1] + nums[end];
                if (curMinSum > target) {
                    end--;
                    continue;   // 当前最小和比目标和大, 没必要操作内双指针(left和right)了, 需要左移end, 跳到下一次计算里
                }

                while (left < right) {
                    bool needInnerContinue = false;
                    if (left >= begin + 2 && nums[left] == nums[left - 1]) {
                        left++;
                        needInnerContinue = true;  // 重复值, 跳过
                    }
                    if (right <= end - 2 && nums[right] == nums[right + 1]) {
                        right--;
                        needInnerContinue = true;  // 重复值, 跳过
                    }
                    if (needInnerContinue) {
                        continue;
                    }

                    int sum = nums[begin] + nums[left] + nums[right] + nums[end];
                    if (sum < target) {
                        left++;
                    } else if (sum > target) {
                        right--;
                    } else {
                        rst.push_back({nums[begin], nums[left], nums[right], nums[end]});
                        left++;
                        right--;
                    }
                }

                end--;
            }

            begin++;
        }

        return rst;
    }
};
```
