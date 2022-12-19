### 解题思路
这一题设计到了多个知识点，一开始一直写错。

#### 1. python 的 deepcopy
之前从某一题的官方题解中（不是岛屿的最大面积那一题）看到标记数组可以写为：
+ avai = [[True]*n for _ in range(n)]
如果写成下面这个样子是错误的
+ avai = [[True]*n]*n
 
但是即使是 avai = [[True]*n for _ in range(n)], 也会导致 简单的 copy 并不奏效，需要使用 deep copy
因为 avai 现在存储的仍然是 [True]*n 的地址值，copy(avai) 只是把地址值给copy去了。仍然会出错。
需要用：
+ prev_avai = copy.deepcopy(avai)


#### 2. nonlocal 或者函数的形参列表
这里由于出现了一条赋值语句 avai = prev_avai， 所以函数会认定 avai 是 local variable, 但前面又有 对 avai 的某个变元改值，所以会导致错误。
两种解决方法：
+ 1. 使用 nonlocal 关键字声明，这样会使得 avai 升级为非局部变量，更细节的部分参考题解 [gelthin-复习python global-nonlocal](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/gelthin-fu-xi-python-global-nonlocal-by-gelthin/)
+ 2. 使用函数形参列表传递 avai 变量，def dfs(tmp, i, avai), 这样每个函数自己用自己的，不会相互影响，这样也是对的。

需要注意到为什么这里： 

+ res 既不需要声明 nonlocal, 也不需要用函数形参列表传递，但可以在内部使用 res.append()，来记录所有界
+ 先前的回溯算法常用的 visited 也是既不需要声明 nonlocal, 也不需要用函数形参列表传递， 但可以修改 visited[i][j]
+ 甚至用形参列表传递的 def add(a): a.append(1)  会导致 原变量 a 的值也发生了变化。 见 《流畅的Python》 
+ 但是如果是单值变量就算是修改变量了，这样就会报错。先前有一个习题碰到此，[gelthin-回溯递归-nonlocal-count-到备忘递归-DP](https://leetcode-cn.com/problems/combination-sum-iv/solution/gelthin-hui-su-di-gui-dao-bei-wang-di-gui-dp-by-ge/) 对应知识点 nonlocal count count += 1


```python3
def dfs():
    print(begin)  # UnboundLocalError: local variable 'begin' referenced before assignment
    begin += 1

begin = 1
dfs()

def dfs():
    print(begin) # Correct
    begin.append(1)
    
begin = []
dfs()
```
#### 3. 回溯法控制顺序，必须前一次取了值，才能进入下一层

最开始写了错误的循环
```python3
for i in range(n):
    for j in range(n):
        if avai[i][j]:
            do something
```
这样会导致潜在解不是按照每一层往下进行遍历，而是说第一个值可以从整个矩阵n*n 任何一个位置，第二个值也是这样。这就会导致很多重复解，防止把一个解调动一下顺序被当做新的解。甚至生成了错误的解。
例如：如果首先选中了(3,3), 由于我下面对角线代码的bug,
从当前元素往对角线右下，左下填 False, 但没有往右上，左上填False, 导致 [(3,3),(2,2),(1,1),(0,0)] 也成了可行解。


``` python3
if not any (avai[i]):
    return
for j in range(n):  # 必须要从第 i 行取一个值
    if avai[i][j]:
        do something
```


### 代码

```python3
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        # def dfs(tmp):
        #     nonlocal avai
        #     if len(tmp) == n:
        #         res.append(tmp)
        #         return
            
        #     for i in range(n):   # BUG， 会导致res 中解大量重复， 不是按照 i 从小到大排列
        #         for j in range(n):
        #             if avai[i][j]:
        #                 prev_avai = avai.copy() # 造一个副本 # BUG, 应该用 deepcopy
                        
        #                 for k in range(n):  # 同行列
        #                     avai[i][k] = False
        #                     avai[k][j] = False
                        
        #                 k = 0
        #                 while i+k<n and j+k<n:
        #                     avai[i+k][j+k] = False #对角线
        #                     k += 1
                        
        #                 k = 0
        #                 while i+k<n and j-k>=0:
        #                     avai[i+k][j-k] = False # 对角线
        #                     k += 1

        #                 dfs(tmp+[[i,j]])
        #                 avai = prev_avai  
        #                 # bug， 有了此，修改了对象，不在是同一个对象，就必须 用 nonlocal, 昨天做的一题还碰到此
        
        # avai = [[True]*n for _ in range(n)]
        # res = []
        # dfs([])
        # result = []
        # for x in res:
        #     matrix = [['.']*n for _ in range(n)]
        #     for i,j in x:
        #         matrix[i][j] = 'Q'
        #     result.append(matrix)
        
        # return result

        def dfs(tmp, i):
            nonlocal avai
            if len(tmp) == n:
                res.append(tmp)
                return
            if not any (avai[i]):
                return

            for j in range(n):
                if avai[i][j]:
                    import copy
                    prev_avai = copy.deepcopy(avai) # 造一个副本 # BUG, 应该用 deepcopy
                    
                    for k in range(n):  # 同行列
                        avai[i][k] = False
                        avai[k][j] = False
                    
                    k = 0
                    while i+k<n and j+k<n:
                        avai[i+k][j+k] = False #对角线右下，这里i只会变大，没有考虑左上，
                        k += 1
                    
                    k = 0
                    while i+k<n and j-k>=0:
                        avai[i+k][j-k] = False # 对角线左下， 这里i只会变大，没有考虑右上，
                        k += 1

                    dfs(tmp+[[i,j]], i+1)
                    avai = prev_avai  
                    # bug， 有了此，修改了对象，不在是同一个对象，就必须用 nonlocal, 昨天做的一题还碰到此
    
        if n<1:
            return [[]]
        avai = [[True]*n for _ in range(n)]
        res = []
        dfs([], 0)
        result = []
        for x in res:
            
            matrix = []
            for i,j in x:
                matrix.append('.'*(j)+'Q'+'.'*(n-1-j))
            result.append(matrix)
        
        return result
```