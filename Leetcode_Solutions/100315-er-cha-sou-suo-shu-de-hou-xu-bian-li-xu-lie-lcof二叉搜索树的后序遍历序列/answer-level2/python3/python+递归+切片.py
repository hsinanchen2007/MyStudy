### 解题思路
递归三步走：
1. 确定函数的功能，即返回什么。
verifyPostorder： 输入一个列表，返回该列表是否是二叉排序树饿后序排列
2. 边界条件：
假设是一个空列表，肯定是一个后序遍历序列，return True（如果规定不含空树的话，可以设为列表只含一个值
3. 递归条件
对于一个二叉排序树来说，其左边的值小于根节点的值，右边的值大于根节点的值
如果序列是一个二叉排序树的后序遍历序列，那么该序列必然能以列表最后一个值（根节点的值）分成两部分，前半部分全小于该值，后半部分均大于该值，如果不能划分的话，直接return False，如果可以的话吗，递归的考察被分开之后的两部分，是否同样满足这个条件。

### 代码

```python3
class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        if not postorder:
            return True
        # if len(postorder) == 1:
        #     return True
        root = postorder[-1]
        i = 0
        cut = len(postorder)-1 # 分割点
        while i < len(postorder)-1:
            if postorder[i] > root:# 第一个大于root的值为分割点
                cut = i
                while i<len(postorder):# 如果在第一个大于root点之后还有小于root的值，直接返回False
                    if postorder[i] < root:
                        return False
                    i+=1
            i+=1
        return self.verifyPostorder(postorder[:cut]) and self.verifyPostorder(postorder[cut:len(postorder)-1])
```