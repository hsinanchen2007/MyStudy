
因为方块的标记字母范围为{'A', 'B', 'C', 'D', 'E', 'F', 'G'}，所以刚好可以用一个字节表示不同的字母。
例如`0001 1001` 表示`ADE`。即可以用这种形式表示每一个节点的字母集合。
那么，每一层就可以用一个字节数组表示了，数组的长度逐层减1。

同理，allowed数组也可以用二维byte数组表示.

思路：从左到右遍历每一层的节点，生成下一层节点的可能取值：
- 如果取值为0，则表示该层这两个节点不存在于allower数组中，可以直接返回false。
- 当该层遍历完之后，进入下一层，直至当前层只有一个元素

```
func pyramidTransition(bottom string, allowed []string) bool {
  // 用位图表示最底下这层
  bits := make([]byte, len(bottom))
  for i := range bottom {
    bits[i] |= 1 << (bottom[i] - 'A')
  }

  // 将allowed数组转换为二维数组
  matrix := make([][]byte, 8)
  for i := range matrix {
    matrix[i] = make([]byte, 8)
  }
  for i := range allowed {
    x := byte(allowed[i][0] - 'A')
    y := byte(allowed[i][1]- 'A')
    matrix[x][y] |= 1 << (allowed[i][2] - 'A') 
  }
  return bfs(matrix, bits)
}


func bfs(matrix [][]byte, bits []byte) bool {
  size := len(bits)
  if size == 1 {
    return true
  }
  
  newBits := make([]byte, size - 1) // 上一层的bits
  for i := range newBits {
    // 根据当前层第i和第i+1个节点的可能取值的组合 填充每一个父节点
    for bit := 0; bit < 8; bit++ { 
      if bits[i] & (1 << bit) > 0 {
        for nextBit := 0; nextBit < 8; nextBit++ {
          if bits[i+1] & (1 << nextBit) > 0 {
            newBits[i] |= matrix[bit][nextBit]
          }
        }
      }
    }
  
    if newBits[i] == 0 { // 没有得到可能取值
      return false
    }
  }
  return bfs(matrix, newBits)
}
```
