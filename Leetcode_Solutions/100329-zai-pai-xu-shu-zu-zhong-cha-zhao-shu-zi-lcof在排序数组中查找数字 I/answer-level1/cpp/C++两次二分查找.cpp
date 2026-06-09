```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int idx_l = binary_search_l(nums, target);
        if (idx_l == -1) return 0;
        int idx_r = binary_search_r(nums, target, idx_l);
        return idx_r - idx_l + 1;
    }
    int binary_search_l(vector<int>& data, int k)
    {
        int l = 0, r = data.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (data[m] >= k) //确保找到的是最小下标
                r = m;
            else
                l = m + 1;
        }
        if (data[l] == k) return l;
        else return -1;
    }
    int binary_search_r(vector<int>& data, int k, int l)
    {
        int r = data.size() - 1;
        while (l < r) {
            int m = r - (r - l) / 2; //注意这里，若用l+会死循环
            if (data[m] == k)
                l = m;
            else
                r = m - 1;
        }
        return l;
    }
};