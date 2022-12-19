### 解题思路
认真写，注意不要将某次的sum初始化为0了，因为整个数组的和可能就是0。

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        long sum = 0;
        for (auto n : A) {
            sum += n;
        }
        long target = sum/3;
        int i = 1;
        long tmp = A[0];
        while (tmp != target && i<A.size()) {
            tmp += A[i];
            i++;
        }
        if (i > A.size()-2) {
            return false;
        }
        tmp = A[i];
        i++;
        while (tmp != target && i<A.size()) {
            tmp += A[i];
            i++;
        }
        if (i > A.size()-1) {
            return false;
        }
        return true;
    }
};
```