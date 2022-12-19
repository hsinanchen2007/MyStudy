### 解题思路
1. 根据n, m 生成对应矩阵
2. 将矩阵转化成二维数组以方便处理
3. 根据 indices 分别将矩阵的行和对应的列 + 1 使其生成全新的矩阵
4. 获取矩阵中奇数的个数，并输出
### 代码

```ruby
# @param {Integer} n
# @param {Integer} m
# @param {Integer[][]} indices
# @return {Integer}
require 'matrix'
def odd_cells(n, m, indices)
  # 生成矩阵
  matrix = Matrix.build(n, m){0}
  matrix = matrix.to_a

  # 根据 indices 信息给对应的每一行每一列都 + 1
  indices.each do |indexs|
    row_index = indexs[0]
    col_index = indexs[1]
    m.times { |t| matrix[row_index][t] += 1 }
    n.times { |t| matrix[t][col_index] += 1 }
  end

  # 打印 矩阵
  p matrix

  # 检测矩阵奇数
  odd_number = 0
  matrix.each do |m|
    m.each do |el|
      el % 2 == 0 ? '' : odd_number += 1
    end
  end

  odd_number
end
```