### 解题思路
本题一定程度上类似第一题两数之和的hash解法
首先为去重，先对数组排序
其次每个数查找之前的hash中，是否为target，如果是，计数加一
最后更新hash表，加入当前数参与的数对，所需要的目标数到hash表中
### 代码

```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<int> s;
        int res = 0;
        bool flag = false;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i-1] == nums[i]) {
                if (k == 0 && !flag) {
                    ++res;
                    flag = true;
                }
                continue;
            }
            flag = false;
            auto it = s.find(nums[i]);
            if (it != s.end()) {
                ++res;
            }
            s.insert(nums[i] + k);
        }
        return res;
    }
};
```