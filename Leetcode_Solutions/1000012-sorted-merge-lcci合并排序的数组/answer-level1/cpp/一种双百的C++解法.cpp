### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/3a3c4938a823d9e83316403afa007339c4ea83ebefbc7f999c0925e67463eda2-image.png)

解题思路：
从后向前比较，把大的数依次由后往前放。

优化思路：（结合代码看）
由于B中的数是要填进A中，那么可以把第一个`while`循环里的条件`j >= 0`挪到前面；


### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m - 1;
        int j = n - 1;
        int t = m + n - 1;

        while (j >= 0 && i >= 0) {
            if (A[i] > B[j]) {
                A[t--] = A[i--];
            } else {
                A[t--] = B[j--];
            }
        }

        while (j >= 0) {
            A[t--] = B[j--];
        }
    }
};
```