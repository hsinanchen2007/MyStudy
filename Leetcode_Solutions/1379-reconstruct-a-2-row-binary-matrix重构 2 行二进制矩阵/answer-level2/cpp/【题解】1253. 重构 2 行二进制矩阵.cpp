**方法一：构造**

设数组的第零行为 `A`，第一行为 `B`。当 `colsum[i]` 的值为 `0` 或 `2` 时，我们将对应的 `A[i]` 和 `B[i]` 置为 `0` 或 `1` 即可，这也是唯一的重构方法。但当 `colsum[i]` 的值为 `1` 时，我们既可以设置 `A[i]` 为 `1`，也可以设置 `B[i]` 为 `1`，此时我们就需要考虑给出的每行元素之和 `upper` 和 `lower` 了。

假设数组 `colsum` 中有 `j` 个 `1` 和 `k` 个 `2`，那么在处理完所有的 `2` 之后，每行的元素之和分别还剩下 `upper - k` 和 `lower - k`。因此我们可以在遇到 `colsum` 中前 `upper - k` 个 `1` 时，将 `A[i]` 设置为 `1`，其余情况将 `B[i]` 设置为 `1`。

我们还需要知道什么时候不存在符合要求的答案。第一种情况就是当 `(upper - k) + (lower - k) != j` 时，此时 `colsum` 之和不等于 `upper` 与 `lower` 之和，因此一定不存在答案。第二种情况是当 `upper - k < 0` 或 `lower - k < 0` 时，由于 `colsum` 中 `2` 的个数比较多，因此没有办法将这些列都设置为 `1`。

```C++ [sol1]
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        if (upper + lower != accumulate(colsum.begin(), colsum.end(), 0)) {
            return vector<vector<int>>();
        }
        
        int k = accumulate(colsum.begin(), colsum.end(), 0, [](int acc, int cur) {
            return cur == 2 ? acc + 1 : acc;
        });
        upper -= k;
        lower -= k;
        if (upper < 0 || lower < 0) {
            return vector<vector<int>>();
        }
        
        int n = colsum.size();
        vector<vector<int>> matrix(2, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 2) {
                matrix[0][i] = matrix[1][i] = 1;
            }
            else if (colsum[i] == 1) {
                if (upper > 0) {
                    matrix[0][i] = 1;
                    --upper;
                }
                else {
                    matrix[1][i] = 1;
                }
            }
        }
        return matrix;
    }
};
```

```Python [sol1]
class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        if upper + lower != sum(colsum):
            return []

        k = sum(x == 2 for x in colsum)
        upper, lower = upper - k, lower - k
        if upper < 0 or lower < 0:
            return []

        n = len(colsum)
        matrix = [[0] * n for _ in range(2)]
        for i in range(n):
            if colsum[i] == 2:
                matrix[0][i] = matrix[1][i] = 1
            elif colsum[i] == 1:
                if upper > 0:
                    matrix[0][i] = 1
                    upper -= 1
                else:
                    matrix[1][i] = 1
        return matrix
```

**复杂度分析**

- 时间复杂度：$O(N)$，其中 $N$ 是数组 `colsum` 的长度。

- 空间复杂度：$O(1)$，这里不计入作为返回值的答案数组的空间。