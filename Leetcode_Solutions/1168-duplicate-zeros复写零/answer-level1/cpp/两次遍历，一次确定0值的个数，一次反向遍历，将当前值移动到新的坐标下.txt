### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        if (arr.empty()) {
            return;
        }
        int zero = 0;
        for (auto n : arr) {
            if (n == 0) {
                ++zero;
            }
        }

        // 没有0或者全是0，直接返回，无需移动
        if (zero == 0 || zero == arr.size()) {
            return;
        }

        int sz = arr.size();
        for (int i = sz - 1; i >= 0; --i) {
            if (zero == 0) {
                break;
            }
            if (arr[i] == 0) {
                --zero;
            }

            if (i + zero <= sz - 1) {
                arr[i + zero] = arr[i];
            }
            arr[i] = 0;
        }
    }
};
```