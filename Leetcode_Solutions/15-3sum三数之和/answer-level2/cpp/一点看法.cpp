### 解题思路
个人觉得，有两点需要注意：
1、边界条件，全正数、全负数、全零
2、去重可以用set来实现，排序后在set里自动去重了

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        vector<vector<int>> allres;

        int size = nums.size();
        if (size < 3) {
            return allres;
        }

        sort(nums.begin(), nums.end());
        int x = 0;
        if (nums[x] > 0 || nums[size - 1] < 0) {
            return allres;
        }

        if (nums[x] == 0 && nums[size - 1] == 0) {
            vector<int> tmp = { 0, 0, 0 };
            allres.push_back(tmp);
            return allres;
        }

        for (x = 0; x < size; x++) {
            int L = x + 1;
            int R = size - 1;
            while (L < R) {
                int sum = nums[x] + nums[L] + nums[R];
                if ( sum == 0) {
                    vector<int> tmp = { nums[x], nums[L], nums[R] };
                    res.insert(tmp);
                    L++;
                    R--;
                } else if (sum > 0) {
                    R--;
                } else {
                    L++;
                }
            }
           
        }

        for (set<vector<int>> :: iterator i = res.begin(); i != res.end(); i++) {
            allres.push_back(*i);
        }
        return allres;
    }
};
```