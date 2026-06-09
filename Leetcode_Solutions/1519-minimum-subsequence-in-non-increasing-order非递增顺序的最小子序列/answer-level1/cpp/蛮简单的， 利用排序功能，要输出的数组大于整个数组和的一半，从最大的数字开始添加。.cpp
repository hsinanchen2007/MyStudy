### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> res;
        vector<int> org(nums);
        int total = 0;
        int resTotal = 0;

        for (auto &ele : nums) {
            total += ele;
        }
        //cout << total / 2 << endl;
        sort(org.begin(), org.end());
        if (nums.size() == 1) {
            return nums;
        }
        for (int i = org.size() - 1; i >= 0; i--) {
            if (resTotal <= total / 2) {
                resTotal += org[i];
                res.push_back(org[i]);
                cout << org[i] << total /2 << endl;
            } else {
                break;
            }
        }
        return res;
    }
};
```