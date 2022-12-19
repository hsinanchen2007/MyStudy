### 解题思路
没什么好说的

### 代码

```cpp
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int ans = 0;
        int n = A.size(), m = A[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n-1; j++){
                if(A[j][i] > A[j+1][i]){
                    ans ++;
                    break;
                }
            }
        }
        return ans;
    }
};
```