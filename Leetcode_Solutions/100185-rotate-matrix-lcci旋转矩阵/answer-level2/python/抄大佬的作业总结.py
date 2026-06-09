### 解题思路
本题我自己想了好多办法，虽然发现了顺时针旋转90度的算法思路，但是因为题干中提及了不可用额外内存，在此处被卡住了，然后求助了各位大佬的解题步骤。
下方提交的步骤是以为叫新杰的大佬的解题步骤，我只是把参数名字按照自己的理解去定义了一下。
大佬的思路很有趣，我自己的理解是：
首先把第一行，第一列，最后一行和最后一列围成的方框看做一个滑轨框（所以我把限制坐标的参数写作了rail）
交换的想法是确定四个点（假定四个角abcd），顺序交换为bcda，便完成了一部分的旋转。
每次交换都设定四个点，而轮交换选定的四个点由一个参数控制，这个参数我定义为了flag_for_four
flag的移动规律为轨道的延伸方向
以第一行这个轨道为例子，左上角第一个元素[0][0]，是这个轨道的起点，往右侧移动就是它的轨道方向，以此类推，右上角的元素为起点，移动方向是向下，右下角为起点移动方向向左，左下角为起点移动方向向上。
我们可以想象有四辆矿车分别在四个角落，在在做完第一轮交换之后，四个角落的矿车按照我上边说的各个轨道方向移动一位，然后将这四个新的位置的元素顺序交换一下，一直继续道矿车走到自己轨道的终点为止。
这样最外圈轨道上的元素交换就完成了。
然后轨道缩圈，这就是rail_x +1和rail_y-1的意思
为了防止跑过一次的轨道圈再被跑一次，比如一个5X5的矩阵 rail_x=2 rail_y=3的轨道环实际上跟rail_x=3 rail_y=2的轨道环是同一个。
为了防止这种情况发生，设定了rail_x要小于rail_y的条件，如果这两个参数想等，说明指向了最中间的中心元素，这个元素只有在奇数行列的矩阵中存在，不需要被旋转
以上就是我从大佬的解题中理解的想法。
而我另一大疑问，也就是如何做到不用额外内存就交换矩阵，似乎这种四个元素同时调换用一个等号就完成了，这一点我也是觉得学到了

不过为了学习一些新知识。我从MichaelWU0726的解题中的链接里学习了一个两个元素交换位置不需要额外储蓄的方法
这个三步异或法真的很有趣：
x = x^y
y = x^y
x = x^y
感觉学到了很多东西，谢谢各位的解题分享
### 代码

```python
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        rail_x = 0
        rail_y = len(matrix)-1
        max_length = len(matrix)-1

        while rail_x < rail_y:
            for flag_for_four in range(rail_x,rail_y):
                matrix[rail_x][flag_for_four],matrix[flag_for_four][rail_y],matrix[rail_y][max_length-flag_for_four],matrix[max_length-flag_for_four][rail_x] = matrix[max_length-flag_for_four][rail_x],matrix[rail_x][flag_for_four],matrix[flag_for_four][rail_y],matrix[rail_y][max_length-flag_for_four]
            rail_x+=1
            rail_y-=1
```