### 方法一 暴力
```cpp
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int cur = arr[0], cnt = 1, n = arr.size();
        for (int i = 1; i < n; ++i) {
            if (arr[i] == cur) {
                ++cnt;
                if (cnt * 4 > n) return arr[i];
            }
            else {
                cur = arr[i];
                cnt = 1;
            }
        }
        return -1;
    }
};
```

### 方法二 二分查找
```cpp
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), span = (n >> 2) + 1;
        for (int i = 0; i < n; i += span) {
            auto iter_l = lower_bound(arr.begin(), arr.end(), arr[i]);
            auto iter_r = upper_bound(arr.begin(), arr.end(), arr[i]);
            if (iter_r - iter_l >= span) return arr[i];
        }
        return -1;
    }
};
```