```
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if(A.empty()){
            return A;
        }
        int stacksize = A[0].size();
        stack<bool> stacks;
        for(int i = 0; i < A.size(); ++i) {
            for(int j = 0; j < stacksize; ++j) {
                if(A[i][j] == 1) {
                    stacks.push(0);
                } else {
                    stacks.push(1);
                }
            }
            for(int k = 0; k < stacksize; ++k) {
                A[i][k] = stacks.top();
                stacks.pop();
            }
        }
        return A;
    }
};
```
![image.png](https://pic.leetcode-cn.com/d24756a33366d87474824d2a3f46675318e0ac5390a60d692fc7ee4cff19f852-image.png)
