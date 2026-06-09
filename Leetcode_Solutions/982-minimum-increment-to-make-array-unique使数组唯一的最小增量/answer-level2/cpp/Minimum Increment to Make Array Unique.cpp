### 解题思路
Minimum Increment to Make Array Unique

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
    int count = 0;
    sort(A.begin(), A.end());
    for (int i = 1; i < A.size(); ++i) 
    {
        int diff = A[i - 1] - A[i] + 1  ;    
        count  +=  max(0,  diff );
        A[i]   +=  max(0,  diff );
    }
    return count;
    }

};
```