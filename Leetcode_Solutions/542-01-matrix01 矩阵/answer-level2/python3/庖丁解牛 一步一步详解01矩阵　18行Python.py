## 第一步　总体框架
面对这道题，我们可以先想一个总体思路
+ 新建一个和原来矩阵大小相同的矩阵
+ 遍历原来矩阵的每个值
+ 计算原来矩阵值上到0的距离
+ 更新新矩阵
如果我们庖丁解牛一下，把第四步的计算用一个函数来替代，我们不难写出这样的代码
### 框架代码如下
```Python
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        def count(row_index, col_index, point):
            pass

        distance_matrix = [[0 for i in range(len(matrix[0]))] for _ in range(len(matrix))]
        for row_index, row in enumerate(matrix):
            for col_index, point in enumerate(row):
                distance_matrix[row_index][col_index] = count(row_index, col_index, point)
        return distance_matrix
```
## 第二步　添砖加瓦
框架很好搭建，剩下的`count()`函数才是难点和核心。如果你不够熟练的话，要记住，碰到最短路径的题，要先往BFS，也就是`广度优先搜索`的方向想。什么是`广度优先搜索`呢？
### 思想
+ 首先找到给定节点，判断它是否为0，这个初始节点当作第0层，此时`distance`为0。
+ 找到初始节点周围四个坐标，这四个节点当作第一层，此时`distance`为１，判断它们是否为０。
+ 再找到这四个节点周围八个节点，这八个节点当作第二层。
+ 重复以往，层层递进。

思路很好理解对吧，就是一个从中间向外扩散的过程。可是怎么实现呢？
### 实现
这里就要介绍一下`队列`，因为`广度优先搜索`和`队列`是好基友。
什么是队列？就是一个先进先出的数组，和我们日常生活中的排队很像。当我们向队列插入一个新数的时候，它插在最后，当我们取出一个数的时候，要从头取。
> **补充**——**关于在`Python`中使用队列**
> 在 `Python` 中，可以使用以下几种方法实现队列
> + `collections`包里的`deque`，对应操作
>     + `pop()`从尾取出
>     + `appendleft()` 从头插入 
> + `queue`包中的`Queue`，对应操作
>     + `put()` 插入
>     + `get()` 取出
> + 直接使用`list`，只要保证只使用
>     + `pop()` 取出
>     + `insert(0,)` 插入
>      或者只使用
>     + `append()` 插入
>     + `list[0]`并且`del list[0]` 取出
>     两者使用`list`方法的不同就区别于你把哪个当头，哪个当尾
>
> 三种方法各有优劣。
> + 第一种是正统的Python的双端队列，缺点是调用的函数有点复杂，可能一不小心写了`append`，就不对了。
> + 第二种使用封装的函数很直接，`put()`和`get()`不容易搞混淆。但是`Queue`类型其实里面本身就装了一个`deque`，有点脱裤子放X的感觉。
> + 第三种优势在于不用调包，但是函数使用逻辑可能造成混淆。在
> 这里，完整版代码采用第二种，好理解，精简版代码采用第三种，省行数。三种方式可以按照你的喜好互相替换，完全不影响结果。
> + 经评论区提醒，补充一下，使用列表时，list.insert(0, )的时间复杂度是O(n)，跟deque是有区别的。deque的appendleft(val)的时间复杂度是O(1)。所以用deque更好。

为什么`广度优先搜索`和`队列`能勾搭到一块儿？

我们可以这样利用`队列`实现`广度优先搜索`。
1. 我们设置一个队列，先把初始点添加进去。
2. 规定每轮把队列中所有点取出，这一轮代表着相同的`distance`，所以`distance`先加一。
3. 分别对取出的每个点的坐标判断是否为０，是则返回，否则把这个坐标的邻居放到队列中。
4. 当这个队列不为空的时候，继续执行步骤２。
5. 由于题目保证有解，所以之前的每轮使用`while True:`就行，一般情况下用`while queue:`，即队列不为空的时候。

因为每次从队列整体取出的时候代表相同的距离，所以可以保证使用`队列`能够实现`广度优先搜索`。

这里罗嗦一句，关于`邻居结点`的遍历，这个很简单，就是横纵坐标加加减减的４个，但是有些小技巧可以大大减少行数。
例如，如果给定点`(x,y)`，遍历它的四个邻居，可以这么写：
```Python
for new_x, new_y in zip((x, x, x + 1, x - 1),(y + 1, y - 1, y, y)):
```
这是一个利用`zip()`函数的小技巧。

那么接下来，完整的`count()`函数就呼之欲出了。
### `count()`完整函数
```Python
def count(row_index, col_index, point):
        if point == 0:return 0
        else:
            que, distance = [(row_index, col_index)], 0
            while que:
                distance, length = distance + 1, len(que)
                for _ in range(length):
                    new_point = que.pop()
                    for new_i, new_j in zip((new_point[0], new_point[0], new_point[0] + 1, new_point[0] - 1),(new_point[1] + 1, new_point[1] - 1, new_point[1], new_point[1])):
                        if 0 <= new_i < len(matrix) and 0 <= new_j < len(matrix[0]):
                            if matrix[new_i][new_j] != 0: 
                                que.insert(0,(new_i, new_j))
                            else: return distance
```


## 第三步　细节修缮
刚刚的代码组合起来已经可以通过所有测试点了，你可能长舒一口气觉得大功告成了，然而很遗憾的是它**不够好**。如果测试样例对时间要求再严苛一点，就过不了了。
因为在上述我们会将很多重复的结点添加到队列中。
例如：

+ 如果我们把(2,2)作为初始的节点
+ 那么第一层会添加(2,3)
+ 第二层又会添加一遍(2,2)，这里还把它当作`distance = 2`的节点，这不是脱裤子放Ｘ嘛？

毫无疑问后面的层所访问的相同结点会有更多的步数，所以舍弃就好了。怎么舍弃呢？

我们添加一个`集合`，里面添加了所有处理过的坐标。如果一个点在这个集合里，那么就不再将它进行比较，也不再将它放到队列中。同时，如果是一个新坐标，那么放到队列中的同时也要放在这个集合当中。注意集合的`in`访问是常量时间的，相当于哈希表，和列表的搜寻是不同的。
### 完整代码如下
这里为了减少`count()`函数的缩进，把对０的判断写在了主函数里，显得更优雅。
```Python
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        def count(row_index, col_index):
            que, distance, visited = [(row_index, col_index)], 0, set()
            while que:
                distance, length = distance + 1, len(que)
                for _ in range(length):
                    new_point = que.pop()
                    for new_i, new_j in zip((new_point[0], new_point[0], new_point[0] + 1, new_point[0] - 1),(new_point[1] + 1, new_point[1] - 1, new_point[1], new_point[1])):
                        if 0 <= new_i < len(matrix) and 0 <= new_j < len(matrix[0]) and (new_i,new_j) not in visited:
                            if matrix[new_i][new_j] != 0: 
                                que.insert(0,(new_i, new_j))
                                visited.add((new_i,new_j))
                            else: return distance
        distance_matrix = [[0 for i in range(len(matrix[0]))] for _ in range(len(matrix))]
        for row_index, row in enumerate(matrix):
            for col_index, point in enumerate(row):
                distance_matrix[row_index][col_index] = 0 if matrix[row_index][col_index] == 0 else count(row_index, col_index)
        return distance_matrix
```

# 第四步 他山之石
怎么还有？别怕，我们已经做完了。
因为在题解里发现了不用`BFS`的做法，所以一并分享一下。仅有15行，很强大。
原链接在　[这里](https://leetcode-cn.com/problems/two-sum/solution/jian-dan-de-liang-ci-bian-li-jie-jue-by-habbi/)
### 思路
不用想的那么复杂，其实就是遍历两次就可以了。

每个非0点到0的距离，跟它上下左右到0的距离有关，所以第一次遍历先将左上两个位置的非0点最小者加1更改。

这样就是从左上往右下看，非0点到0的最短距离，但是这样还不知道从右下到左上看的最短距离。

所以再从右下到左上遍历，注意这次更新除了要取右下两个点的最短距离之外，还要跟当前位置的点做一次最小值比较，因为右下可能距离更远。
### 代码
```Python
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                l,t= 10001,10001
                if matrix[i][j] != 0:
                    if i > 0: t = matrix[i - 1][j]
                    if j > 0:　l = matrix[i][j - 1] 
                    matrix[i][j] = min(l,t) + 1
        for i in range(len(matrix) - 1, -1 ,-1):
            for j in range(len(matrix[0]) - 1, -1, -1):
                r,b = 10001,10001
                if matrix[i][j] != 0:
                    if i < len(matrix) - 1: b = matrix[i + 1][j]
                    if j < len(matrix[0]) - 1:r = matrix[i][j + 1]
                    matrix[i][j] = min(matrix[i][j], min(r,b) + 1)
        return matrix

作者：habbi
链接：https://leetcode-cn.com/problems/two-sum/solution/jian-dan-de-liang-ci-bian-li-jie-jue-by-habbi/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```