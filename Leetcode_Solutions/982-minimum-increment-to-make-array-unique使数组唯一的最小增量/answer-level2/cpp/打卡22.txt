### 解题思路
  排个序，后一个向前一个对比。对比的是前一个加一的数字t，如果后一个数字要大于等于t的，就不用进行操作了。否则要加的步骤数，就是t减去当前数字的差。当然，要更新值。

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin() , A.end());
        int s = 0;
        for(int i = 1 ; i < A.size() ; i++){
            int t = A[i - 1] + 1;
            if(A[i] >= t)continue;
            s += t - A[i];
            A[i] = t;
        }
        return s;
    }
};
```