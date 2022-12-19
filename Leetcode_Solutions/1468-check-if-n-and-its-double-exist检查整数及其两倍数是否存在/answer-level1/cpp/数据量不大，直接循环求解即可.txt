### 解题思路
遍历数组每个数，按照题目条件判断就好了：
i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]

### 代码

```cpp
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for (auto it = arr.begin(); it != arr.end(); it++) {
            int M = *it;
            int N = M * 2;
            auto pos = find(arr.begin(), arr.end(), N);
            if (pos != arr.end() && pos != it) {
                return true;
            }
        }
        return false;
    }
};
```