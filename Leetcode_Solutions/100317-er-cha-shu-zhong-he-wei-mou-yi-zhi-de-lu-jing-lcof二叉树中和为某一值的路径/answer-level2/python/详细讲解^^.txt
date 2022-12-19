### 解题思路
题意就是从根节点到子节点的所有路径中是否存在值是一个固定数值的数字。
分析：
（1）首先二叉树类型的题目往往都是通过递归的方式去做，大体的框架要知道，我们先简单定义一个递归的方法：
    
```python []
    def solve(root,num)：
        pass
    # 这个函数的意思是说，以root为根节点的子树是否含有从根到叶子数值为num的路径
    # 我们通过root来找，肯定是再把这个任务交个root.left和root.right,
    # 题目是要找出路径，我们就要把这个也加在递归函数里 ,可能路径有多条，也要
    def solve(root,num,path，pathes):
        pass

```
（2）题目还有一个非常明显的特征，要求是**根**到**叶子**，这种：**以叶子节点作为结束的条件**，都一定要判断root是不是叶子，在确定root是叶子的基础上才继续做判断

```python []
    def isLeafNode(root):
        if root.left == None and root.right == None :
            return True
        else:
            return False
```
（3）整体代码逻辑
```python []
    def solve(root,num,path,pathes):
        if root == None:
            return 
        if isLeafNode(root): # 到了叶子结点才判断
            if root.val == num:
                path.append(root.val)
                pathes.append(path)
            return # return 下面的代码才不运行

        #  到每个节点都会分裂成两个新的路径
        #  python里面提供了浅拷贝方法 b = arr[:] , 相当于b就是新的数组 
        solve(root.left, num-root.val, path[:]+ [root.val], pathes)
        solve(root.right, num-root.val, path[:]+ [root.val], pathes)



```