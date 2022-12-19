### 解题思路
1、从头开始遍历，求差cha = A[1] - A[0]，这个时候判断A[2]的时候，就看A[2] - A[1] 是不是等于cha，如果是，那么A[2]也是这个等差数列的一项，等差数列变长，如果不是那么此时需要求现在等差数列里面可以包含多少个子数组。这里我们需要用一个from来标记等差数列的起点index
2、计算子数组的方法，按照题目要求，子数组的长度必须大于等于3，小于等于等差数列数组的长度。那么当子数组长度为等差数列长度的时候，子数组个数是1；子数组长度为等差数列长度-1的时候，子数组个数是2；以此类推，这就是个等差数列求和。 假设等差数列长度是size，那么子数组个数就是 1+2+3...+(size-3+1)= (size-2)*(size-1)/2;

### 代码

```cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }
        int cha = A[1] - A[0];
        int res = 0;
        int from = 0;
        int i = 2;
        while (i < A.size()) {
            if (A[i] - A[i-1] != cha) {
                int size = i-1 - from + 1;
                if (size >= 3) {
                    res += (size-1)*(size-2)/2;
                }
                from = i-1;
                cha = A[i] - A[i-1];
            }
            i++;
        }
        int size = i-1 - from + 1;
        if (size >= 3) {
            res += (size-1)*(size-2)/2;
        }
        return res;
    }
};
```