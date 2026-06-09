### 解题思路
下一个字典序的算法：从最高字段往左开始，假如是x位置的，找到他右边数组(x + 1, n)的第一个大于他的值，然后交换，最后排序（x+1, n), 输出；如果一直到最左侧字段还未找到，就整体排序。
通过字典序往结果中追加，与第一个数组重复就停止。

### 代码

```cpp
class Solution {
public:
    void nextPermute(vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 0; --i) {
            sort(nums.begin() + i + 1, nums.end());
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] < nums[j]) {
                    swap(nums[i], nums[j]);
                    sort(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
        }

        sort(nums.begin(), nums.end());
        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(nums);
        nextPermute(nums);

        while (nums != res[0]) {
            res.push_back(nums);
            nextPermute(nums);
        }

        return res;
    }
};
```