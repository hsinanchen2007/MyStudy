# 一、思路

为了寻找树中与目标值k距离最近的叶节点，我们需要下述三部分信息：

**1. 目标值k对应节点的位置**

**2. 叶节点对应的位置和数值**

**3. 节点之间的距离**

不难得知，对于任意树而言，只需遍历一次即可获得目标值k对应节点的位置和叶节点的信息。问题的重点在于，**如何计算节点之间的距离**。

这里，我们可以对二叉树进行坐标化，再利用不同节点的坐标计算距离

# 二、二叉树的坐标化：

这里，我们将二叉树的坐标化定义为：

**用节点所在的层数layer和位置pos记录节点在二叉树中整体的位置。**

其中，层数不必多解释，而位置是指，**该节点在满二叉树中在这一层是第几个节点**。

层数和位置都从0开始。

对于一个3层的二叉树，其坐标化如下图：

![二叉树.png](https://pic.leetcode-cn.com/e11472aab30ee8193e412c07760344ed256fc340382fb853bdb3cfa605c44dbf-%E4%BA%8C%E5%8F%89%E6%A0%91.png)
不难看出，对于任意节点(x,y)而言，其左、右子节点坐标分别为(x+1,y×2)和(x+1,y×2+1)。

由此，我们便可以对二叉树进行坐标化。

# 三、距离的计算：

**1. 两节点处于不同layer时：**

对于任意的两个节点坐标(x0,y0)和(x1,y1)，要比较其距离，我们首先应让两个节点处于同一水平线。

因此对于较低或者说x值（即layer）较大的节点，我们需要让其不断上移为其父节点，直至x0==x1，上一过程中，返回值即节点的距离+1。

由上述的关系可知，对于任意节点(x,y)，其父节点的坐标为(x-1,y//2)。


**2. 两节点处于同一layer时：**

当两节点处于同一层时，此时只需要考虑pos。如果 y0!=y1，需要不断上移两个节点，直到他们重合在同一节点处。由于该上移过程涉及到两个节点，所以返回值即节点距离+2.

# 四、代码+注释

```
class Solution:
    def distance(self,x0,y0,x1,y1):                    # 根据两个节点的坐标计算距离
        res = 0
                                                     # 如果两个节点不在同一层
                                                     # 首先让layer较大的节点
                                                     # 即较低的节点上移，变成其父节点
                                                     # 对于任意节点，x,y
                                                     # 其父节点坐标为 x-1,y//2
                                                     # 相应地，距离+1
        while x0 > x1:                                
            x0 -= 1
            y0 //= 2
            res += 1
        
        while x0 < x1:
            x1 -= 1
            y1 //= 2
            res += 1
        
        while y0 != y1:                              # 当两节点处于同一层时
                                                     # 需要比较其pos
                                                     # 当pos相等时，两节点即重合
                                                     # 否则两个节点同步上移
                                                     # 由于其layer相等，只需考虑pos
                                                     # 对于任意 pos=y 的节点而言
                                                     # 其父节点pos = y//2
                                                     # 每次上移，距离+2
            y0 //= 2
            y1 //= 2
            res += 2
        
        return res

    def findClosestLeaf(self, root: TreeNode, k: int) -> int:
        leaf = []                                    # 记录所有叶节点的坐标
        queue = [(0,0,root)]                         # 层序遍历的队列，（0,0）为根的坐标
        x,y = 0,0                                    # 记录目标值所对应坐标

        while queue:
            layer,pos,node = queue.pop(0)            # 队列弹出的值分别为层数、位置和节点

            if node.val == k:                        # 如果找到了坐标值，将其记录下来
                x = layer
                y = pos

            if not node.left and not node.right:      # 如果节点为叶节点
                leaf.append((layer,pos,node.val))     # 记录其坐标和节点值
                continue

            if node.left:                             # 如果节点有左节点
                                                      # 不难想象其坐标值为：
                                                      # layer = layer + 1
                                                      # pos = pos * 2
                queue.append((layer+1,pos*2,node.left))
            
            if node.right:                            # 如果节点有右节点
                                                      # 不难想象其坐标值为：
                                                      # layer = layer + 1
                                                      # pos = pos * 2 + 1
                queue.append((layer+1,pos*2+1,node.right))
                                                    
                                                      # 利用lambda函数和distance
                                                      # 求出距离最小的叶节点
                                                      # 并返回其节点值
        return min(leaf,key=lambda p:self.distance(p[0],p[1],x,y))[2]
```
