## 规律，碰壁转向
**碰到边界，就转向！**
显而易见，方向顺序是固定的：右，下，左，上
我们利用访问数组$visited$和矩阵自身的范围来构造边界
 1. 特判，当$matrix$为空时，返回$[]$
 2. 定义矩阵行数$M$，矩阵列数$N$。定义访问数组$visited$为$M*N$数组，全部初始化为$False$。定义方向列表$directions=[[0,1],[1,0],[0,-1],[-1,0]]$，分别对应右，下，左，上。定义当前访问行列索引$m=0$,$n=0$。定义**方向计数器**$count=0$。定义结果列表$res$
 3. 因为矩阵含有$M*N$个元素，因此遍历$M*N$次，对于每次遍历：
 	* 将$Matrix[m][n]$加入$res$。并令访问数组$visited[m][n]$置为$True$，代表这个位置已经访问了。
 	* 取出当前方向$dir\_x=directions[count][0],dir\_y=directions[count][1]$，判断下一步是否越界：
 		+ 越界条件由三部分组成：$0<=m+dir\_x<M$表示行在矩阵范围内，$0<=n+dir\_y<N$表示列在矩阵范围内，$visited[m+dir_x][n+dir_y]$为$False$表示下一步没有被访问，即没有碰到边界。若同时满足，说明下一步没有越界，则更新$m,n$，$m+=dir\_x，n+=dir\_y$。
 		+ 若不满足边界条件，说明**碰壁**了，需要换方向，更新方向计数器$count=(count+1)\%4$，**变换方向后是一定不会碰壁的** ，从而更新$m,n$， $m=m+directions[count][0]$，$n=n+directions[count][1]$。
 
 4. 返回$res$

### 复杂度分析
 - 时间复杂度：$O\left(n\right)$，因为遍历一次矩阵。
 - 空间复杂度：$O\left(n\right)$，需要额外的$visited$来保存边界。

### Python

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:return []
        res=[]
        M,N=len(matrix),len(matrix[0])
        visited=[[False]*N for _ in range(M)]
        directions=[[0,1],[1,0],[0,-1],[-1,0]]
        m,n,count=0,0,0
        for i in range(M*N):
            res.append(matrix[m][n])
            visited[m][n]=True
            dir_x,dir_y=directions[count][0],directions[count][1]
            if(0<=m+dir_x<M and 0<=n+dir_y<N and not visited[m+dir_x][n+dir_y]):
                m+=dir_x
                n+=dir_y
            else:
                count=(count+1)%4
                m,n=m+directions[count][0],n+directions[count][1]
        return res
         
```


## 逆时针旋转（不当人系列）
### 先修
矩阵旋转：

 1. 顺时针旋转：先将矩阵转置，再左右逆置。详细可见[48,旋转图像CSDN](https://blog.csdn.net/zhushaojiecumt/article/details/102899568)或[48,旋转图像leetcode](https://leetcode-cn.com/problems/rotate-image/solution/zhi-jie-xuan-zhuan-ju-zhen-ni-zhi-de-xing-zhi-tu-j/)
2.逆时针旋转：先转置，再上下逆置。道理和1一致，可自己画图。
### 算法流程
因此，一个想法是：每次将矩阵的第一行取出来，放入$res$，对剩下的矩阵逆时针旋转，重复以上步骤。
![在这里插入图片描述](https://pic.leetcode-cn.com/40cb0d48a561db1710099af4bfa75e05c43e04e38601b5ac6fa66e9ed35880d2.png)
将第一行加入$res$，并从矩阵中删除。此时$res=[1,2,3]$，$Matrix$如下：
![在这里插入图片描述](https://pic.leetcode-cn.com/64ec2a3452311368f19d3dc1c21d611893e0ebf57dde6b01bc4b307992f777ee.png)
转置：
![在这里插入图片描述](https://pic.leetcode-cn.com/f829291ef79ef9980ff65c553a6ed058509fe13b06775882dca84014d18d5cc4.png)   
上下逆置：
![在这里插入图片描述](https://pic.leetcode-cn.com/f260e761db539123150f9e2e90b952d5d0b9ea41e18a1ebd6d00ac37529b7904.png)
**重复以上步骤！**
### 复杂度分析
暂未分析

### Python
**附上
[map用法](https://www.runoob.com/python/python-func-map.html)
[zip用法](https://www.runoob.com/python/python-func-zip.html)
[*参数的使用](https://www.cnblogs.com/xujiu/p/8352635.html)**

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        while matrix:
            res += matrix.pop(0)
            matrix = list(map(list, zip(*matrix)))[::-1]
        return res
         
```
