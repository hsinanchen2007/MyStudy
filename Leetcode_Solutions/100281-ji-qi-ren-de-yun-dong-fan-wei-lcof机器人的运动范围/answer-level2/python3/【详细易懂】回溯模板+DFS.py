分析：这道题和前面的[矩阵中的路径](https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/)非常类似，都是在矩阵中按照一定的规则来走完整个矩阵，像这样的矩阵中走路的题目，很大可能都是用回溯来进行求解。（回溯可以理解为树的遍历，可以是DFS也可以是BFS，由于每种情况都遍历，所以时间复杂度一般来说是很高的）
解题思路：机器人在矩阵中可以走上下左右四个位置，所以很直观的来想，我们需要一个函数其中有个位置变量可以包含这四种情况，然后又想到每次都可以选择四个不同的方向走，分别尝试每种情况，如果走不通就退回到原来的位置，这样我们就可以想到用DFS，因为这样可以把四个方向的情况的所有可能都遍历到，这样也就容易联想到回溯。
下面是回溯的模板：
```
def dfs(当前状态):
    if 当前状态为边界状态: #考虑边界条件
    记录或输出
    return;
    for i in range(x)		#遍历树所有子节点
    //扩展出一个子状态。
    修改了全局变量
    if 子状态满足约束条件:
        dfs(子状态)
    恢复全局变量//回溯部分
```


本题**回溯函数的构造**：

1. **考虑变量的个数**
2. **考虑矩阵中边界条件**
3. **考虑路径的表达**


- 第一步：对于写回溯函数第一步就是考虑如何选择合适的**变量**来表达机器人走的状态。这里能想到首先是矩阵的位置，这里就包含了机器人走的位置和矩阵长度的变量。
接下来我们继续考虑限制条件，也就是机器人可以如何走路，题目告诉我们机器人不能进入行坐标和列坐标的数位之和大于k的格子，所以这里又需要一个变量k以及一个用来记录已经走过的格子的变量visited。
总结一下所有变量为：i（当前状态横坐标），j（当前状态纵坐标），m（总的行数），n（总的列数），visited（标记访问状态），k（阈值）

考虑好了所有变量，接下来就可以考虑如何走路的问题了。
- 第二步：这里有两个需要考虑的**边界**：

1. 机器人不能走到方格外面（i<0 or i>=m or j<0 or j>=n）
2. 不能进入行坐标和列坐标的数位之和大于k的格子(行坐标+列坐标>k or visited[i][j]==True)
（这里行坐标和列坐标处理我们直接另写一个function）

- 第三步：最后我们可以直接写出**子状态的回溯函数**：
向左-DFS(i-1,j,m,n,visited,k)
向右-DFS(i+1,j,m,n,visited,k) 
向下-DFS(i,j-1,m,n,visited,k)
向上-DFS(i,j+1,m,n,visited,k)

最后有一点需要注意就是题目求的是能达到格子的数目，所有我们返回最终的数目需要额外+1（也可以这样极端考虑，当子状态所有都不能走，那只能在一个格子处了，所以最后也是返回1）

下面是完整的代码：
```python []
def movingCount(self, m, n, k):

    visited=[[False for _ in range(n)] for _ in range(m)] #定义标记访问状态
    return self.DFS(0,0,m,n,visited,k) #初始状态是原点

def DFS(self,i,j,m,n,visited,k):

    if i<0 or i>=m or j<0 or j>=n or self.cal(i)+self.cal(j)>k or visited[i][j]==True: #边界条件
        return 0

    visited[i][j]=True
    #回溯子状态
    return self.DFS(i-1,j,m,n,visited,k)+self.DFS(i,j-1,m,n,visited,k)+self.DFS(i+1,j,m,n,visited,k)+self.DFS(i,j+1,m,n,visited,k)+1
    

def cal(self,num): #计算行坐标和列坐标数位和

    total=0
    while num>0:
        total+=num%10
        num//=10
    return total
```




参考：http://chen-tao.github.io/2017/01/27/al-template/