### 解题思路
左数组右界为pos，左数组最大值为maxval
迭代数组A，curmaxval记录迭代的最大值。 注意maxval是A[0,pos]的最大值，curmaxval是A[0,i]的最大值。
如果当前值A[i] >= maxval，跳过
如果当前值A[i] < maxval, pos置为i,同时，将maxval置为curmaxval。

### 代码

```cpp
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int pos = 0, maxval = A[0], curmaxval = A[0];
        for (int i = 0; i < A.size(); ++i) {
            curmaxval = max(curmaxval, A[i]);
            if (A[i] >= maxval) continue;
            pos = i;
            maxval = curmaxval;
        }
        return pos+1;
    }
};
```