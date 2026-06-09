### 解题思路
首先，将`matrix`所有行顺序反转，再将反转后`matrix`变为其转置矩阵即符合题意。

顺序反转用到了`Array#reverse!`，
转置矩阵是将当前矩阵的上三角（下三角）元素沿对角线交换，
即`matrix[i][j]`与`matrix[j][i]`交换。
这里的代码迭代的是"上三角"元素，也就是对角线以上的部分。

### 代码

```ruby
# @param {Integer[][]} matrix
# @return {Void} Do not return anything, modify matrix in-place instead.
def rotate(matrix)
  n = matrix.size
  matrix.reverse!
  i = 0
  while i < n
    j = i
    while j < n
      temp = matrix[i][j]
      matrix[i][j] = matrix[j][i]
      matrix[j][i] = temp
      j += 1
    end
    i += 1
  end
end
```

执行用时 :36 ms, 在所有 Ruby 提交中击败了100.00%的用户
内存消耗 :9.4 MB, 在所有 Ruby 提交中击败了100.00%的用户