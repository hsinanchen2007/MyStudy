### 解题思路
![image.png](https://pic.leetcode-cn.com/f79ae319d026c2e466250f3ceafa86adff83e5b6179c725967b67723de674eb1-image.png)

- 运用递归的思路来不断的判断子树是否是一颗二叉搜索树,运用二叉搜索树的性质:左子树的节点值比根节点的小,右子树的节点值比根节点的大;在一个后续遍历的序列中,位于序列最后的元素是根节点
- 所以可以总结出一个后序序列可划分成`['左子树','右子树','根节点']`这三部分组成,顺序是严格的
- 好了,有了上面的特性,我们使用一个例子进行分析:
![image.png](https://pic.leetcode-cn.com/cf2d0fb5602eb77b0b218a679fa9d0960fedbadacf6d8bc983c4ba07d789ecfe-image.png)

1. 划分左子树,我们能知道现在这个树的根节点为[5],从头开始遍历节点,直到我们遇到比根节点大的或者根节点,之前那些比根节点小的值是左子树的节点,此树的左子树序列为[1]
2. 划分右子树,可以看到当遍历到6的时候,6>5,按照上面总结的规律,说明6之后到根节点的序列都应该是右子树,即[6,3,2],这是就需要判断下是否在右子树的序列中存在比根节点小的元素,如果有的话就说明是不符合条件的,显然[3,2]都是比[5]要小的,不符合条件
3. 如果不存在在右子树中比根节点小的元素,递归的遍历上述左右子树

### 代码(看注释)

```python
class Solution(object):
    def verifyPostorder(self, postorder):
        """
        :type postorder: List[int]
        :rtype: bool
        """
        if not postorder:
            return True
        def isTree(postorder):
            root = postorder[-1]
            length = len(postorder)
            for i in range(length): # 找到左子树的区间,此时注意下这样的切分不可能出现左子树中的节点比根节点大
                if postorder[i] > root:
                    break
            
            for j in range(i, length-1):# 如果右子树中存在比根节点的小的值,那么是不符合条件的
                if postorder[j] < root:
                    return False

            left = True
            if i > 0:
                left = isTree(postorder[:i])#判断左子树是否符合条件
            right = True
            if i < length -1 :
                right = isTree(postorder[i:-1])#判断右子树是否符合条件
            return left and right
        return isTree(postorder)

```