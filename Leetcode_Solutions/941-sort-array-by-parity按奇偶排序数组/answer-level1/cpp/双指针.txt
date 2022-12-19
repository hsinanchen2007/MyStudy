### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int left = 0, right = A.size() - 1;
        while (left <= right) {
            while (left <= right && (A[left] & 1) == 0) {
                ++left;
            }

            while (right >= left && (A[right] & 1)) {
                --right;
            }

            if (left < right) {
                swap(A[left], A[right]);
            }
        }
        return A;
    }
};
```