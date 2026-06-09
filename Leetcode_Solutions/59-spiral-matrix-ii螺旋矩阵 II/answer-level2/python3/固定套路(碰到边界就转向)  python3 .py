# 题解
有了54.螺旋矩阵的基础，解决本题轻而易举。可回顾[54.螺旋矩阵CSDN](https://blog.csdn.net/zhushaojiecumt/article/details/102920530)或者[54.螺旋矩阵LeetCode](https://leetcode-cn.com/problems/spiral-matrix/solution/peng-bi-zhuan-xiang-ni-shi-zhen-xuan-zhuan-tu-jie-/)
## 碰壁转向
**碰到边界，就转向！**
显而易见，填写数字方向顺序是固定的：右，下，左，上
我们利用结果数组$res$中已填写的数字和给定的矩阵的范围来构造边界
 1. 定义最终结果$res$为$n*n$的矩阵，全部初始化为$False$，表示未填充数字。
 2. 定义方向列表$directions=[[0,1],[1,0],[0,-1],[-1,0]]$，分别对应右，下，左，上。定义当前访问行列索引$x=0$,$y=0$。定义**方向计数器**$count=0$。
 3. 需要填写$n*n$次，因此需要遍历$n*n$次，遍历范围$[1,n*n]$：
 	* 令$res[x][y]$等于$i$。表示已经填入数字。
 	* 取出当前方向$dir\_x=directions[count][0],dir\_y=directions[count][1]$，判断下一步是否越界：
 		+ 越界条件由三部分组成：$0<=x+dir\_x<n$表示行在矩阵范围内，$0<=y+dir\_y<n$表示列在矩阵范围内，$res[x+dir_x][y+dir_y]$为$False$表示下一步填写位置还未填写，即没有碰到边界。若同时满足，说明下一词填写没有越界，则更新$x,y$，$x+=dir\_x，y+=dir\_y$。
 		+ 若不满足边界条件，说明**碰壁**了，需要换方向，更新方向计数器$count=(count+1)\%4$，**变换方向后是一定不会碰壁的** ，从而更新$x,y$， $x=x+directions[count][0]$，$y=y+directions[count][1]$。
 
 4. 返回$res$

### 复杂度分析
 - 时间复杂度：$O\left(n^{2}\right)$，因为遍历一次矩阵。
 - 空间复杂度：$O\left(n^{2}\right)$

### Python

```python
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res=[[False]*n for _ in range(n)]
        directions=[[0,1],[1,0],[0,-1],[-1,0]]
        x,y=0,0
        count=0
        
        for i in range(1,n*n+1):
            res[x][y]=i
            dir_x,dir_y=directions[count][0],directions[count][1]
            if(0<=x+dir_x<n and 0<=y+dir_y<n and not res[x+dir_x][y+dir_y]):
                x=x+dir_x
                y=y+dir_y
            else:
                count=(count+1)%4
                x=x+directions[count][0]
                y=y+directions[count][1]
        return res
         
```
