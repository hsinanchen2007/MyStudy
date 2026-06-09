```cpp
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int minAbs = 1000000;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 1; ++i) {
            int tmp = arr[i + 1] - arr[i];
            if (tmp < minAbs) {
                minAbs = tmp;
                res = { { arr[i], arr[i + 1] } };
            }
            else if (tmp == minAbs)
                res.emplace_back(vector<int>{ arr[i], arr[i + 1] });
        }
        return res;
    }
};
```