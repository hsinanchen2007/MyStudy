一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 解题思路
二叉搜索树有：

- 结点值:左<根<右
- 左右子树都是搜索树

后序遍历顺序为：左->右->根

- 最后一个数为根结点，通过根节点值切割左右子树。
- 判断左右子树是否二叉搜索树

对于[4,8,6,12,16,14,10]

```
    10
 6     14  
4 8  12   16
```


### 代码

```python
def helper(sequence):
    if len(sequence) <= 1: return True
    root = sequence[-1]
    for i in range(len(sequence)):
        if sequence[i] > root:
            break
    for j in range(i, len(sequence)-1):
        if sequence[j] < root:
            return False
    return helper(sequence[:i]) and helper(sequence[i:-1])

class Solution(object):
    def verifyPostorder(self, sequence):
        if not sequence: return True
        return helper(sequence)
```