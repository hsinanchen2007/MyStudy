### 解题思路
参考逆序对的思路

### 代码

```cpp
class Solution {
public:
    vector<int> res;
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<pair<int, int>> vec;
        for(int i = 0; i < nums.size(); ++i) {
            vec.emplace_back(make_pair(nums[i], i));
        }
        res = vector<int>(nums.size(), 0);
        merge_sort(vec, 0, nums.size()-1);
        return res;
    }

    void merge_sort(vector<pair<int, int>>& nums, int start, int end) {
        if (start < end) {
            //int mid = (start+end)/2;
            int mid = start + (end - start) / 2;
            merge_sort(nums, start, mid);
            merge_sort(nums, mid+1, end);
            merge(nums, start, mid, end);
        }
    }

    void merge(vector<pair<int, int>>& nums, int start, int mid, int end) {
        int i = start;
        int j = mid+1;
        int k = end;
        vector<pair<int, int>> sort_nums;
        while(i <= mid && j <= end) {
            if (nums[i].first <= nums[j].first) {
                res[nums[i].second] += j - mid - 1;
                sort_nums.push_back(nums[i++]);
            } else if (nums[i].first > nums[j].first){
                sort_nums.push_back(nums[j++]);
            }
        }
        while(i <= mid) {
            res[nums[i].second] += j-mid-1;
            sort_nums.push_back(nums[i++]);
        }
        while(j <= end) {
            sort_nums.push_back(nums[j++]);
        }
        for(int i = 0, j = start; i < sort_nums.size(); ++i, ++start) {
            nums[start] = sort_nums[i];
        }
    }
};
```