### 解题思路
使用一个arr来存放当前结果，a_end来标识arr当前使用的最大下标
arr[a_end] = num;
combinationSum3(num+1, arr, a_end+1, k, n-num); 结果集中选择当前num
combinationSum3(num+1, arr, a_end, k, n); 结果集中不选择当前num

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp(k+1, 0);
        combinationSum3(1, tmp, 0, k, n);
        return result;
    }
    void combinationSum3(int num, vector<int>& arr, int a_end, int k, int n) {
        if (!n && a_end == k) {
            vector<int> tmp(arr.begin(), arr.begin()+a_end);
            result.emplace_back(std::move(tmp));
            return;
        }
        if (num > 9 || n < 0 || a_end > k) return;
        arr[a_end] = num;
        combinationSum3(num+1, arr, a_end+1, k, n-num);    // 选择当前数字
        combinationSum3(num+1, arr, a_end, k, n);          // 不选择当前数字
    }
};
```