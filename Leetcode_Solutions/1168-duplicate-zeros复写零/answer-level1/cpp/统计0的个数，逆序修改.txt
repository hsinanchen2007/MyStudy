### 解题思路
统计0的个数，逆序修改

### 代码

```cpp
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        if (arr.empty())
            return;
        int n = arr.size();
        int z = 0;
        for (int i : arr)
            z += i == 0;
        for (int i = n - 1; i >= 0; --i) {
            if (i + z < n)
                arr[i + z] = arr[i];
            if (arr[i] == 0) {
                z--;
                if (i + z < n)
                    arr[i + z] = 0;
            }
        }
    }
};
```