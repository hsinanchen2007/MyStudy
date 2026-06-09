### 解题思路
本题限制了数组arr1的值范围，0~1000，联想到计数排序，使用数组下标代替数值，统计元素个数

### 代码

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        if (arr2.empty()) {
            sort(arr1.begin(), arr1.end());
            return arr1;
        }

        int arr[1001] = {0};
        for (auto n : arr1) {
            ++arr[n];
        }
        vector<int> res;
        res.reserve(arr1.size());
        for (auto n : arr2) {
            res.insert(res.end(), arr[n], n);
            arr[n] = 0;
        }
        // 处理剩余未出现在arr2中的数
        for (int i = 0; i <= 1000; ++i) {
            if (arr[i] == 0) {
                continue;
            }
            res.insert(res.end(), arr[i], i);
        }
        return res;
    }
};
```