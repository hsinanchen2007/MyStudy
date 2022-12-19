### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size()){
            return false;
        }
        int index = 0;
        while (true) {
        while (index < A.size() && A[index] != B[0]) {
            index += 1;
        }
        int j = index,  i = 0;
        while (j < A.size() && A[j] == B[i]) {
            i += 1, j += 1;
        }
        if (j == A.size()) {
            break;
        } else {
            index += 1;
        }
        }
        int i = 0;
        index = B.size() - index;
        while (index < B.size()) {
            if (A[i++] != B[index++]) {
                return false;
            }
        }
        return true;
    }
};
```