### 解题思路
两个指针分别从数组的最左侧、右侧向中间移动，逆序输出大的平方数到目标数组

### 代码

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        if (A.empty()) return {};
        vector<int> ret(A.size());
        int left=0, right=A.size()-1, cur=A.size()-1;
        while (left <= right) {
            ret[cur--] = A[left] * A[left] > A[right] * A[right] ? A[left] * A[left++] : A[right] * A[right--];
        }
        return ret;
    }
};
```
执行用时 :116 ms, 在所有 cpp 提交中击败了87.77%的用户
内存消耗 :13.5 MB, 在所有 cpp 提交中击败了85.35%的用户