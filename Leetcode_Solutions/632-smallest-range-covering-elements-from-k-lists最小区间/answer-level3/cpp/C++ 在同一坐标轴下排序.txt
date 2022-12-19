### 解题思路
1. 首先将所有数组元素与其所在数组序号组成 **元素-区间号**
2. 对元素进行排序
3. 双指针法扫描 

### 代码

```cpp
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> axis;
        vector<int> tmp(2, 0);
        for (int i = 0; i < n; ++i) {
            for (auto& e : nums[i]) {
                axis.push_back({e, i});
            }
        }

        sort(axis.begin(), axis.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        int left = 0;
        vector<int> res{-100000, 100000};
        map<int, int> intervals;
        int len = axis.size();

        for (int right = 0; right < len; ++right) {
            intervals[axis[right][1]]++;
            if (intervals.size() == n) {
                if ((axis[right][0] - axis[left][0]) < (res[1] - res[0]) 
                    || ((axis[right][0] - axis[left][0]) == (res[1] - res[0]) 
                        && axis[left][0] < res[0]))
                {
                    res[0] = axis[left][0];
                    res[1] = axis[right][0];    
                }
            }

            while (left <= right && intervals.size() == n) {
                if ((axis[right][0] - axis[left][0]) < (res[1] - res[0]) 
                    || ((axis[right][0] - axis[left][0]) == (res[1] - res[0]) 
                        && axis[left][0] < res[0]))
                {
                    res[0] = axis[left][0];
                    res[1] = axis[right][0];   
                }

                intervals[axis[left][1]]--;
                if (intervals[axis[left][1]] == 0) {
                    intervals.erase(axis[left][1]);
                }
                left++;
            }
        }

        return res;
    }
};
```