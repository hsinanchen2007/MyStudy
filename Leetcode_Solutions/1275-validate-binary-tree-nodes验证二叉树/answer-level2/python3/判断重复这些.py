### 解题思路
最开始判断上一层的数量和这一层的数量，发现完全没有必要
直接判断重复这些就可以了，把那三个例子的情况都写进if里面

### 代码

```python3
class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: [int], rightChild: [int]) -> bool:
        if leftChild is None and rightChild is None:
            return True
        TreeNode_nums = 1
        TreeNode_dict = {}
        # layer = 1
        # layer_dict = {0: 1, 1: 0}
        # 在这还要弄个等比数列求和来算层数
        for i in range(n):
            if leftChild[i] != -1:
                if leftChild[i] == 0 or TreeNode_dict.get(leftChild[i]):
                    return False
                TreeNode_nums += 1
                TreeNode_dict[leftChild[i]] = 1
                # layer_dict[layer] += 1
            if rightChild[i] != -1:
                if rightChild[i] == 0 or TreeNode_dict.get(rightChild[i]):
                    return False
                TreeNode_nums += 1
                TreeNode_dict[rightChild[i]] = 1
                # layer_dict[layer] += 1

            # if layer_dict[layer - 1] * 2 < layer_dict[layer]:
            #     return False
            # if i + 1 == 1 * (1 - 2 ** layer) / (-1):
            #     layer += 1
            #     layer_dict[layer] = 0
        if TreeNode_nums != n:
            return False
        else:
            return True

# 我把层数这个去掉居然通过了，我感觉这个题目出的有点问题呀，害我白想这么久
```