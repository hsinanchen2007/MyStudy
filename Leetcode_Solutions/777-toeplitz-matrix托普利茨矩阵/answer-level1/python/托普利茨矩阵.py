#### 方法一： 对角线法 【通过】

**思路和算法**

首先要想明白的是怎么判断 `(r1, c1` 和 `(r2, c2)` 这两个点属于一条对角线。通过观察可以发现，在满足 `r1 - c1 == r2 - c2` 的情况下，这两个点属于同一条对角线。

在上面的问题搞清楚的情况下，很容易就可以想到：让 `groups[r-c]` 存储每条对角线上遇到的第一个元素的值，如果之后遇到的任何一个值不等于之前存储的值，那么这个矩阵就不是托普利茨矩阵，否则就是。

```python [solution1-Python]
class Solution(object):
    def isToeplitzMatrix(self, matrix):
        groups = {}
        for r, row in enumerate(matrix):
            for c, val in enumerate(row):
                if r-c not in groups:
                    groups[r-c] = val
                elif groups[r-c] != val:
                    return False
        return True
```

```java [solution1-Java]
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        Map<Integer, Integer> groups = new HashMap();
        for (int r = 0; r < matrix.length; ++r) {
            for (int c = 0; c < matrix[0].length; ++c) {
                if (!groups.containsKey(r-c))
                    groups.put(r-c, matrix[r][c]);
                else if (groups.get(r-c) != matrix[r][c])
                    return False;
            }
        }
        return True;
    }
}
```


**复杂度分析**

* 时间复杂度: $O(M*N)$，即矩阵大小。

* 空间复杂度: $O(M+N)$。

#### 方法二： 检查左上邻居 【通过】

**思路与算法那**

对于每条对角线上的元素，按顺序有 $a_1, a_2, a_3, \dots, a_k$。如果所有对角线上的元素都满足 $a_1 = a_2, a_2 = a_3, \dots, a_{k-1} = a_k$,那么这个矩阵就是 *托普利茨矩阵*。

对于对角线上的元素来说，如果当前元素不是第一个出现的元素，那么它前面的元素一定在当前元素的左上角。可以推出，对于位于坐标 `(r, c)` 上的元素，只需要检查 `r == 0 OR c == 0 OR matrix[r-1][c-1] == matrix[r][c]` 就可以了。

```python [solution2-Python]
class Solution(object):
    def isToeplitzMatrix(self, matrix):
        return all(r == 0 or c == 0 or matrix[r-1][c-1] == val
                   for r, row in enumerate(matrix)
                   for c, val in enumerate(row))
```

```java [solution2-Java]
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        for (int r = 0; r < matrix.length; ++r)
            for (int c = 0; c < matrix[0].length; ++c)
                if (r > 0 && c > 0 && matrix[r-1][c-1] != matrix[r][c])
                    return false;
        return true;
    }
}
```

**复杂度分析**

* 时间复杂度: $O(M*N)$。

* 空间复杂度: $O(1)$。