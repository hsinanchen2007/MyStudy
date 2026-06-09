第一反应就是，观察这个大小为m*m的矩阵，每个元素旋转后的样子。

## 因为刚好是90度，我们可以得到一个结论：坐标(i,j)旋转后的位置，就是(j,m-i-1)。假设从(0,0)开始旋转，把它的值，扔在了它应该出现的位置(0,m-1)上，之后呢？

## 之后也很简单，其实就是，把(0,m-1)上原来的值，继续移动到它应该在的位置，我们画一下图，就会发现，经过若干次之后，旋转回到了最开始的位置
(0,0) 这一轮循环就结束了

## 我们最笨的办法，遍历所有元素，i,j都移动一次，理论上，把所有元素都移动过，整体的就结束了~

## 当然，理论上，在整体移动过程中，肯定存在重复的点又被移动了一次，因为每次移动都会带动n个点一起完成这个圈圈，我们加一个备忘录list来存
所有移动过的点~

时间复杂度O(n) 空间复杂度O(n),但是因为备忘录存的其实是一个元祖(i,j) 所以内存吃的比较多~~~

```
class Solution(object):
    def rotate(self, matrix):
        """
        m大小的
        1.元素[i,j],第i行的第j列元素，旋转后，变成[j][m-1-i]
        2.遍历所有元素(i,j)接下来移动变换后的新位置，替换为自己的值，然后继续旋转，旋转回到最开始的位置[i][j]
        3.下一轮循环
        4.添加备忘录，moved_position，如果已经移动过的点，就不要再移动了
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        if not matrix:
            return matrix
        if not matrix[0]:
            return matrix
        if len(matrix)==1:
            return matrix
        m=len(matrix)
        #已经被移动过的位置
        moved_position=[]
        for i in range(m):
            for j in range(m):
                if (i,j) in moved_position:
                    continue
                temp=matrix[i][j]
                p=self.findNextPosition(m,i,j)
                while p !=(i,j):       
                    nextVal=matrix[p[0]][p[1]]
                    matrix[p[0]][p[1]],temp=temp,matrix[p[0]][p[1]]
                    moved_position.append(p)
                    p=self.findNextPosition(m,p[0],p[1])
                #回到自己的位置
                matrix[i][j]=temp
                moved_position.append((i,j))


        
    def findNextPosition(self,m,i,j):
        return (j,(m-1-i))
```
