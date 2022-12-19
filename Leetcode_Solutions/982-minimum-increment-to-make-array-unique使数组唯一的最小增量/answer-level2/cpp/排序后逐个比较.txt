### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size() == 0) return 0;
        std::sort(A.begin(), A.end());
        int pre = A[0];
        int ans = 0;
        for(int i=1; i < A.size(); ++i){
            if(A[i] <= pre){
                ans += pre - A[i] + 1;
                A[i] = pre + 1;
                pre = A[i];
            }
            else{
                pre = A[i];
            }
        }
        return ans;
    }
};
```