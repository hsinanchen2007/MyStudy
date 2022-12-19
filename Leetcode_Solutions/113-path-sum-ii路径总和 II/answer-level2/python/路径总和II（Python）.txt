这一题就是第112题的进阶版了，第112题只需要我们判断是否存在该路径即可，而此题是需要我们把路径也给找出来，无疑难度增加不少。但其实方法都大同小异，读者对第112题不熟悉的话，可以先看看这篇文章，有个大概印象。
https://leetcode-cn.com/problems/path-sum/solution/lu-jing-zong-he-pyhton-by-fei-ben-de-cai-zhu-uc4q0/

第112题用了两种方法，我也会基于这两种方法给出相应的方法，改动地方不是很多，所以我就不怎么解释了。

方法一：
就是情况最多的那种，代码如下：
```python
class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        # 定义一列表用来保存所有路径
        paths = []

        def traverse(root, sum, path=[]):
            if root is None:
                return 
            if root.left is None and root.right is None:
                new_path = path+[root.val]
                if sum == root.val:
                    paths.append(path+[root.val])
            elif root.left is None:
                traverse(root.right, sum-root.val, path+[root.val])
            elif root.right is None:
                traverse(root.left, sum-root.val, path+[root.val])
            else:
                traverse(root.left, sum-root.val, path+[root.val])
                traverse(root.right, sum-root.val, path+[root.val])
        traverse(root, sum)
        return paths
```
执行效率还是可以，在94%左右。

![image.png](https://pic.leetcode-cn.com/5871c72104d9e0b29023c8fb5e9c86da794573f76c81d43994e2299b7d2fd3d9-image.png)

方法二：
就是情况比较少的那种，代码如下：
```python
class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        # 定义一列表用来保存所有路径
        paths = []

        def traverse(root, sum, path=[]):
            if root is None:
                return 
            if root.left is None and root.right is None:
                new_path = path+[root.val]
                if sum == root.val:
                    paths.append(path+[root.val])
            if root.left :
                traverse(root.left, sum-root.val, path+[root.val])
            if root.right:
                traverse(root.right, sum-root.val, path+[root.val])
            
        traverse(root, sum)
        return paths
```
执行效率有了进一步提升，在100%

![image.png](https://pic.leetcode-cn.com/05d5af883438c8d10208aa508a18a7cc8549ff9341a8fe2707b0c3c7bc5a3fa8-image.png)