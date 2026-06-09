### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void merge_sort(vector<pair<int, int>>& nums, int lo, int hi, vector<int>& res) {
        if (hi - lo <= 1)
            return; // 元素个数 <= 1 终止

        int mid = lo + ((hi - lo) >> 1);
        merge_sort(nums, lo, mid, res);
        merge_sort(nums, mid, hi, res);
        
        int right = mid;
        
        //对于左半区间中的每个元素 left，统计右侧比它小的元素的个数
        for (int left = lo; left < mid; ++left) {
            while (right != hi && nums[left] > nums[right])
                ++right;
            res[nums[left].second] += right - mid;
        }
        /*stl中的归并函数，且是直接在原数组中*/
        inplace_merge(nums.begin() + lo, nums.begin() + mid, nums.begin() + hi);
    }

    vector<int> countSmaller(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        vector<pair<int, int>> v(nums.size());//排序后索引乱了，需要映射保存起来
        for (int i = 0; i < nums.size(); ++i) {
            v[i] = make_pair(nums[i], i);
        }
        
        vector<int> res(v.size());//存放结果
        merge_sort(v, 0, v.size(), res);

        return move(res);
    }
};
```