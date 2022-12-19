对于数组中一个数，如果比它小的最大的两个数之和都不能比这个数大，那么这个数就不可能作为三角形最长边的边长

而反之，三角形的最大周长，就由这三个数和来提供

因此，将数组排序，倒序遍历后三个数能否满足三边关系，满足则返回三数和，如果一直不满足，就说明不能组成三角形

代码：
```
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int len = A.size();
        for (int i = len - 1; i > 1; i--) {
            if (A[i - 2] + A[i - 1] > A[i])
                return A[i - 2] + A[i - 1] + A[i];
        }
        return 0;
    }
};
```
