排序后，将每个数字变为至少比前面的数字大一
### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
    int count = 0;
    sort(A.begin(), A.end());
    for (int i = 1; i < A.size(); ++i) 
    {
        int diff = A[i - 1] - A[i] + 1  ;    //diff表示后者需要比前者大1，所要进行的操作次数
        count  +=  max(0,  diff );
        A[i]   +=  max(0,  diff );
    }
    return count;
    }
};
```