```cpp
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 7) {
            return false;
        }
        vector<int> zipped{nums[0]};
        for (int i = 1; i < n; i++) {
            if (nums[i] == 0 && zipped.back() == 0) {
                continue;
            }
            zipped.push_back(nums[i]);
        }
        n = zipped.size();
        if (zipped.size() < 4 && zipped[0] == 0 && zipped.back() == 0) {
            return true;
        }
        vector<int> sums(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + zipped[i];
        }
        for (int i = 1; i < n - 5; i++) {
            for (int j = i + 2; j < n - 3; j++) {
                if (sums[i] != sums[j] - sums[i + 1]) {
                    continue;
                }
                for (int k = j + 2; k < n - 1; k++) {
                    if (sums[i] != sums[k] - sums[j + 1] || sums[i] != sums[n] - sums[k + 1]) {
                        continue;
                    }
                    return true;
                }
            }
        }
        return false;
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```