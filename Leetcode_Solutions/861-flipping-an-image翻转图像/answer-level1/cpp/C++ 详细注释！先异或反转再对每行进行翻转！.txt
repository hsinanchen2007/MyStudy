### 解题思路
注释很详细了，注意 2 点即可：
 - 异或的运算
 - 同时处理奇数列和偶数列的翻转

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = A[0].size();

        // 1. 在翻转前对每个元素进行反转，与 1 异或，相同为 0，相异为 1
        // 1 ^ 1 = 0
        // 0 ^ 1 = 1
        int tmp = -1;

        for (int r = 0; r < rows; r++) {
            // 2. 注意这里的：c < (cols + 1) / 2，加 1 是为了同时处理列数为奇数和偶数的情况
            // 比如列数 = 3：c < (3 + 1) / 2 = 2，遍历前 2 个元素，中间的元素反转后与自身交换
            // 比如列数 = 4：c < (4 + 1) / 2 = 2（2.5 向下取整），所以列数为偶数刚好也遍历前一半元素
            for (int c = 0; c < (cols + 1) / 2; c++) {
                tmp = A[r][c] ^ 1;
                A[r][c] = A[r][cols - 1 - c] ^ 1;
                A[r][cols - 1 - c] = tmp;
            }
        } 

        return A;
    }
};
```