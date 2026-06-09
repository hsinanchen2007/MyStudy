### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int res = 0;
        int size = A.size();

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
                    res = max(res, up + down + 1);
                    if (start + up + down > size - 2) {
                        break;
                    }
                }
            }
            
            start = start + up + down + (int)(up * down == 0);
            up = 0;
            down = 0;
        }

        return res;
    }
};
```