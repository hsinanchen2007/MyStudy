### 解题思路
记录当前最小的可能值

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int sz = A.size();
        if(sz <= 1){
            return 0;
        }
        sort(A.begin(), A.end());
        int res = 0;
        int pre = A.front() - 1;
        for(int val : A){
            if(val > pre){
                pre = val;
            }else{
                res += (pre - val + 1);
                pre++;
            }
        }
        return res;
    }
};
```