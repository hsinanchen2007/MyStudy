### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        // 快排吧
        quick_sort(arr, 0, arr.size() - 1, k);
        return vector<int>(arr.begin(), arr.begin() + k);
    }

    void quick_sort(vector<int>& arr, int l, int r, int k) {
        if (l >= r) return;

        int x = arr[l], i = l - 1, j = r + 1;
        while (i < j) {
            while (arr[++ i] < x);
            while (arr[-- j] > x);
            if (i < j) swap(arr[i], arr[j]);
        }
        int s1 = j - l + 1;
        if (s1 >= k) quick_sort(arr, l, j, k);
        else quick_sort(arr, j + 1, r, k - s1);
    }
};
```