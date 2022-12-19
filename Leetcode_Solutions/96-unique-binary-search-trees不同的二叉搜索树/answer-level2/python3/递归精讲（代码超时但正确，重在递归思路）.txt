```
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

'''
设计递归：
递归公式：
    1. 首先分析事件的基本性质：
    若定义以 i 为 root 的BST的种类的个数为 num(i)， 则有：
    基本性质
    num(i) = num(1:i-1) * num(i+1:n) 
        即以所有小于i的数作为root，当作i的left root的子树, 乘以所有大于i的数作为root，当作i的right tree
        将两个值乘起来即为以i为 root的总数
    通过观察发现上述基本性质并不是递归关系（即子母事件之间并不是完全相同的运算)。因此我们建立递归关系
    
    2. 建立递归关系：
    
    我们的问题是以小于n的数，组成BST的个数总数。如果我们换一种定义方式：
    
    若我们定义getNum(start, end) 表示从start 到 end 组成的序列的排列方式，则有递归关系：
    
    for i in range(start, end):
        res = res +  getNum(start, i-1) + getNum(i+1, end)
    
    getNum(start, end) = res
    
    这就存在了递归关系。
    
2. 递归出口：
    递归方向是 start和end逐步相向而行，那么递归出口必然就是start和end相遇为止：即start > end or start = end 我们具体分析一下：
    
    当 start == end 说明什么？ 
        说明该子树只有一个元素，而只有一个元素的子树的种类是 1
    
    当 start > end 说明什么？
        说明该子树不应该在BST中存在，就是说该子树不含元素。而作为递归，说明该root没有左或者右子树（左/右子树为空），而空子树的种类是多少？
        是1， 
    
    综上递归出口应该是start >= end 即为递归出口，且return 1 

3. 边界情况；
    当n=0， 1， 2 时候。
    初始调用时， start = 1 end = n
    n=0, 会自动进入到出口， return 1 正确
    n=1,也会进入到出口
    n=2，开始递归。。。。
    
    因此边界情况已经在递归出口中包括了。
    
4. 代码实现：
'''

class Solution:
    def numTrees(self, n: int) -> int:
        return self.getNum(1, n)

    def getNum(self, start, end):
        # 递归出口
        res = 0
        '''
        递归中关于同名变量的问题：
        在递归中，函数中的变量都是local var，在递归深入的过程中，被压入堆栈中，因此即使在不同层的递归中，同名变量被重新赋予了新的值，
        也不会影响其他层的值，这也是看递归的一个角度，即在一层递归中，所有语句只被执行一遍，与其他层无关。
        
        这里res是初始赋值， 在每一层中，res都会被置0， 但每次被置0的res并不是同一个变量。在一层中，res只会被置零一次。并不会随着递归频繁置零。
        
        
        
        因此我们在检查递归的时候，只要走一遍递归，看看递归规律是否正确，而后关注递归出口的几个递归，是否可以正确从出口出来。
        '''



        if start >= end:
            return 1

        for i in range(start, end+1):
            left_num = self.getNum(start,i-1)
            right_num = self.getNum(i+1, end)
            res = res + left_num * right_num

        return res


```
