### 解题思路
思路来自 **珍珠好好吃** 作者，位运算非常棒！

### 代码

```python
class Solution:
  def isUnique(self, astr):
    mark = 0   #26个字母，因此假设mark是26位二进制数000...0000
    for char in astr:
      move_bit = ord(char) - ord('a')
      m = 1 << move_bit  #计算机存储是按二进制数存储 进行左移
      if (mark & (1 << move_bit)) != 0:  #若值为1 证明前面存在过这个字符
        return False
      else:
        mark |= (1 << move_bit)
    return True

```