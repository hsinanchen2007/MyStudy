### 解题思路
双指针

### 代码

```cpp
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int res = 0;
        int size = A.size();
        if (size < 3) {
            return res;
        }

        int start = 0;
        int up = 0, down = 0;
        while (start + up < size - 1) {
            if (A[start + up + 1] > A[start + up]) {
                up++;
                continue;
            } 

            if (up > 0) {
                while (A[start + up + down + 1] < A[start + up + down]) {
                    down++;
                    if (start + up + down > size - 2) {
                        break;
                    }
                }
                if (down > 0) {
                    res = max(res, up + down + 1);
                }
            }
            
            start = start + up + down;
            if (up * down == 0) {
                start++;
            }
            up = 0;
            down = 0;
        }

        return res;
    }
};
```