### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        if (arr.size() <= 1) {
            return vector<vector<int>>();
        }
        vector<vector<int>> res;
        if (arr.size() == 2) {
            res.push_back(arr);
            return res;
        }

        sort(arr.begin(), arr.end());
        int min_diff = INT_MAX;
        for (int i = 0; i < arr.size(); ++i) {
            if (i > 0 && min_diff > arr[i] - arr[i-1]) {
                min_diff = arr[i] - arr[i-1];
            }
        }
        for (int i = 0; i < arr.size(); ++i) {
            if (i > 0 && min_diff == arr[i] - arr[i-1]) {
                res.push_back(vector<int>{arr[i-1], arr[i]});
            }
        }

        return res;
    }
};
```