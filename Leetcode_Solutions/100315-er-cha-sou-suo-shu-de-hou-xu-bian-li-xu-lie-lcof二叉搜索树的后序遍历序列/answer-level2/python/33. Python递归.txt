### 解题思路
一般而言关于树的问题都是使用递归方法，当我们确定递归方法之后我们就要想，我们要递归解决什么子问题，而对于这道题而言就是判断每一棵子树都是二叉搜索树，后续遍历按照左子树 -> 右子树 -> 根的顺序进行遍历，而二叉搜索树的性质是，左子树都小于根的值，右子树都大于根的值，我们可以先确定左子树，然后直接划分出右子树，判断右子树是否符合条件，进而获得子问题的解。

### 代码

```python
class Solution(object):
    def verifyPostorder(self, postorder):
        """
        :type postorder: List[int]
        :rtype: bool
        """
        def get_res(postorder):
            length = len(postorder)
            if length <= 1:
                return True
            temp = postorder[-1]
            ind = 0
            list_1 = []
            while ind < length - 1:
                if postorder[ind] < temp:
                    list_1.append(postorder[ind])
                    ind += 1
                else:
                    break
            list_2 = postorder[ind:length - 1]
            for num in list_2:
                if num < temp:
                    return False
            return get_res(list_1) and get_res(list_2)
                
        return get_res(postorder)
```