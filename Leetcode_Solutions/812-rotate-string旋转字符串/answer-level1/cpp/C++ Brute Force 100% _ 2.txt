```cpp
class Solution {
public:
    bool rotateString(string A, string B) {
        int asz = A.size();
        int bsz = B.size();
        if (asz != bsz) return false;
        if (asz == 0) return true;
        for (int i = 0; i < asz; i++) {
            if (B[i] == A[0]) {
                int found = true;
                for (int j = 0; j < asz; j++) {
                    if (A[j] != B[(j+i)%asz]) {
                        found = false;
                        break;
                    }
                }
                if (found) return true;
            }
        }
        return false;
    }
};

```
![WX20200310-002256.png](https://pic.leetcode-cn.com/48241a691eea0499f6d782f96625f6cfead4aa44c1af8853c3a2f1dccada63fc-WX20200310-002256.png)


