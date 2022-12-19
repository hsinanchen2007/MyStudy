### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if (arr.empty()) {
            return arr;
        }
        int rmax = -1, sz = arr.size();
        for (int i = sz - 1; i >= 0; --i) {
            int cur = arr[i];
            arr[i] = rmax;
            rmax = (i == sz - 1) ? cur : max(rmax, cur);
        }
        return arr;
    }
};
```