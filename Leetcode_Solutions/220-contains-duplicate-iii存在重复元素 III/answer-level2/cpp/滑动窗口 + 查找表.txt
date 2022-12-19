太坑了，int会溢出，参考了评论区大佬才A的


```c++
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < k) {
            k = nums.size() - 1;
        }
        set<int> s;
        int l = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - l > k) {
                s.erase(nums[l]);
                l ++;
            }
            auto cmp = s.lower_bound((double)nums[i] - (double)t);
            if (cmp != s.end() && *cmp <= (double)nums[i] + (double)t) {
                return true;
            } else {
                s.insert(nums[i]);
            }
        }
        return false;
    }
    void run() {
        int arr[] = {0, 2147483647};
        int k = 1;
        int t = 2147483647;
        vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
        bool res = Solution().containsNearbyAlmostDuplicate(vec, k, t);
        cout<<"res: "<<res<<endl;
    }
};
```
