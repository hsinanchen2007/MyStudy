### 解题思路
先排序，再对排序好的数组进行遍历，由于可能存在 1113这种数组，所以要用<=，而不是==判断。
还有其他解法看着头疼= =

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(),A.end());
        int ans = 0;
        for(int i=1;i<A.size();i++){
            if(A[i]<=A[i-1]){
                ans += A[i-1]+1 -A[i];
                A[i] = A[i-1]+1;
            }
        }
        return ans;
    }
};
```