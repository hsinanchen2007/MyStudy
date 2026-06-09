### 代码

```cpp
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        for (int i = 0; i < arr1.size(); ++i) {
            if (search(arr2, arr1[i]) && search(arr3, arr1[i])) {
                ans.push_back(arr1[i]);
            }
        }
        return ans;
    }

    bool search(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1, mid = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (target < arr[mid]) {
                r = mid - 1;
            } else if (target > arr[mid]) {
                l = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
```