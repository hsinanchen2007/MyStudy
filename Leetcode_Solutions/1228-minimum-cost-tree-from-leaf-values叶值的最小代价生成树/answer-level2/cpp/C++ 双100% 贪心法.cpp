```
class Solution {
public:
    void helper(vector<int>& arr, int& res) {
        if (arr.size() == 2) {
            res += arr[0] * arr[1];
            return;
        }
        int mn = INT_MAX;
        int mn_ind = 0;
        for (int i = 1; i < arr.size(); ++i) {
            int t = max(arr[i], arr[i - 1]);
            if (t < mn) {
            	mn = t;
            	mn_ind = i;
            }
        }
        if (mn_ind != arr.size() - 1 && arr[mn_ind - 1] > arr[mn_ind + 1]) ++mn_ind;
        res += arr[mn_ind] * arr[mn_ind - 1];
        arr[mn_ind - 1] = mn;
        for (int i = mn_ind; i < arr.size() - 1; ++i) {
            swap(arr[i], arr[i + 1]);
        }
        arr.pop_back();
        helper(arr, res);
    }
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        helper(arr, res);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/0fb1bd313b39c990700609e4785f695b8743ed5e0339a8b98acfc5cc799f05ab-image.png)
