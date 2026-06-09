### 解题思路
lef和rig分别指向左右的数，比较并从最大位开始装

### 代码

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A)
    {
        int len = A.size();
        vector<int> ans(len);
        int a = 0, b = len - 1, i = b;
        while (i >= 0)
        {
            int lef = A[a] * A[a], rig = A[b] * A[b];
            if (lef > rig) ans[i] = lef, a++;
            else ans[i] = rig, b--;
            i--;
        }
        return ans;
    }
};
```