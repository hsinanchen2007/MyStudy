```
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

'''
递归解法：

写递归最重要的点在于：
 不要在乎递归是如何运行的，你要在乎的是，通过设计什么样的递归公式，递归出口，就一定可以通过递归获得最终的值。而不是去考虑递归在计算机中以什么样
 的形式和流程去执行的。



1. 递归公式：
    1）BST的性质： 若以1：n 组成的所有BST中，则以i为root的BST 具有性质：
            i 
           / \
       left  right
       
       left 必然只含有1：i-1的元素
       right 必然也只含有 i+1: n 的元素
       
       以i为root的BST的种类 = left的种类 ，right的种类 之间一一组合，例如left有2种，right有3种，那么一共是6种
       即：
       for l in left:
            for r in right:
                root = val
                root.right = r
                root.left = l
                
        一定注意，这里是一一组合的关系，因此种类是乘的关系，不是加，而乘的组合就是两个for循环的嵌套
       
       而寻找left 和 right就变成了一个 寻找以1：n 组成的所有BST的问题
       
    2）建立递归关系：
        如上分析可以分析如下关系：
        
        以i为root的BST的种类 = 寻找以 1: i-1 的BST的种类 * 以i+1: n的BST的种类
        
        上述问题并不是一个递归关系，且也不是我们所求，我们所求为：
        
        寻找以 1：n 的BST的种类:
        
        于是我们就要建立如下三者之间的关系：
            i) 以 1：n 的BST的种类
            ii)以 1: i-1 的BST的种类
            iii)以i+1: n的BST的种类
            
        之间的关系即可得到递归
        
        若定义：
        left_list 装着所有可能的left的子树，
        同理
        right_list 装着所有可能的right的子树，
        
        其关系如下：
        for root_val in range(start,end+1)
        
            left_list = buildTree(start, root_val-1)
            left_right = buildTree(root_val+1,end)
            
            
            for l in left_list:
                for r in right_list:
                    root = TreeNode(root_val)
                    root.left = l
                    root.right = r
                    
                    res.append(root)
                  
                    
        i) 详细讲解一下几个for循环的作用：
            
            第一个for：
                第一个for循环让所有的从1到n的数值都当一遍root（每个值都做一次皇帝）
            第二个for和第三个for：
                两个for实现了left的所有种类和right的所有种类的 一一组合！！！ 数量上是相乘。
            tree的连接：
                tree的连接只需要关心连接处即可，不需要关心tree内部是什么，怎么样，之间如何排列的。
                只需要两个tree找到位置，对应位置一连即可。
        
        ii) 关于list的问题：
            o 首先list存放的是所有可能的Tree的head (obj)。
            o list的append一定发生在最内的循环，才能包括：所有值做为root的情况下的左右子树的所有可能的复合。
    
    3）设计递归函数：
        因为该递归和起始有关，需要不停迭代来减小子树所包含的数，因此我们定义：
        buildTree(start, end) ——> list[head_Node]
        
    
    4) 递归出口：
        递归中 start 和 end 向中间靠拢，因此出口必然是start和end相遇：我们需要考虑：
            1。start 比 end 少 1的情况
            2。start == end
            3。start > end 的情况
            
        逐条分析：
            当start比end少1，最外层的循环为range(start, start+2) 该子树仍然有两个元素，循环扔需要继续。
            当start == end range(start,start+1)该子树只有一个元素。这个元素仍然需要被添加到tree里面，且下面的循环可以自动添加
            当start > end 的时候 说明该子树是个空子树， 下面的循环没有办法添加None, 因此这就是最后的出口了！！！
            
        综上 出口为 start > end 
                  
'''

class Solution:
    def generateTrees(self, n: int):
        if n == 0 :
            return []
        return self.buildTree(1, n)

    def buildTree(self, start, end):

        #递归出口
        if start > end:
            return [None]

        res = []
        '''
        由于res的初始化出现在function中，因此每次调用（递归）的时候，都会有一个新的res产生。
        注意： 这里是 新的res， 不是同一个。也就说每一次调用的时候，都有一个专属于该递归层的res诞生，尽管各个层的该变量都叫res，但是并不是同一个，
        也不互相影响。
        
        而res的作用是，将以start为开始，end为结束的 所有可能BST的head，都存在在res这个list中。每个res就是一个list。
        
        '''

        for i in range(start, end+1):
            left_sub_tree_list = self.buildTree(start, i-1)
            right_sub_tree_list = self.buildTree(i+1, end)

            # 已经找到了left和right的全部的subtree了，并把所有subtree的head都存在了list里面

            for left_subtree in left_sub_tree_list:
                for right_subtree in right_sub_tree_list:
                    # 开始建立subtree的list
                    root = TreeNode(i)
                    root.left = left_subtree
                    root.right = right_subtree

                    res.append(root)
                    # 这里，只要将right和left与其subtree的头连上就行了，和subtree内部是如何的无关

        return res







```
