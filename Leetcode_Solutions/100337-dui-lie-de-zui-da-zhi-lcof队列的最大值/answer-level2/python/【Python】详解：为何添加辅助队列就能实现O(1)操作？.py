![image.png](https://pic.leetcode-cn.com/271d715e586b971c55af69bfe27889695ae91110c118557bb67f34572d1bfd1e-image.png)

### 前言

看到不少同学直接用`max()`函数，显然这是不符合题目中$O(1)$时间复杂度的。因为`max()`会在列表中检查每一个元素，从而返回最大值，**所以`max()`是$O(n)$的时间复杂度**。
### 思考过程
要想在$O(1)$时间内做到取出最大值，我们可以想到，能否用一个`cur_max`的变量，来记录并且比较每一次新入队的`value`，这个想法是极好的，但是如果队列是`[4,3]`这个样子，`cur_max`只会记下4是最大的，当调用一次`pop_front()`后，此时队列为`[3]`，而`cur_max`没有变化，所以单个变量记录最大值行不通。

进一步地我们可以想到，一个变量不行，那我直接用一个辅助队列记录值OK不OK呢？

答案是OK的。我们让辅助队列的数从大到小排列好，要找最大值直接返回辅助队列的头部即可，同时这也是$O(1)$时间复杂度的操作，完美契合题意。**下面详细讲讲辅助队列怎么能够实现这个操作。**
### 详细步骤
我们先初始化两个队列：
原始队列`que = []`，帮助我们记录**原始数值**。
辅助队列`sort_que = []`，帮助我们**对原始数值进行排序**。

对于原始队列`que`，来一个就装一个，走一个就放一个，没啥好担心的。

重点是这个辅助队列`sort_que`。

#### 第一个问题：**`sort_que`里面怎么排序？**

要回答这个问题，我们首先要知道，队列的性质是**先进先出**。

假设原始队列是`[1,2]`，那么先走的那一位是队列里面的`1`。我们的`sort_que`的头部理应为`2`，因为原始队列`[1,2]`的最大值是2。即使对原始队列`[1,2]`调用`pop_front`造成`1`的离开，最大值依然是2，此时，我们仍然需要保持`sort_que`的头部仍是2。

这个要求，就衍生出了`sort_que`队列的怎么排序了，请看代码：
```
while sort_que and sort_que[-1] < value:
    sort_que.pop()
self.sort_que.append(value)
```
这就是说，如果`sort_que`不为空，并且`sort_que`的最后一位元素小于当前入队元素`value`的话，直接把最后一位元素弹走，直到`sort_que`为空，或`sort_que`的最后一位元素大于等于`value`。这就保证了，`sort_que`的头部总是原始队列`que`的最大值~

#### 第二个问题：**原始队列`que`发生`pop_front`时`sort_que`该怎么变动？**

这个其实比较简单，当`que`弹出的数恰好等于`sort_que`的头部元素时，咱把`sort_que`的头部也跟着弹出就好。请看代码：
```
res = que.pop(0)
if res == sort_que[0]:
    sort_que.pop(0)
```
我们这里的`que`和`sort_que`假设是Python中的list形式，用`pop(0)`的方法可以弹出list的第一个元素，但这个的时间复杂度是$O(n)$，这一点要注意。

![image.png](https://pic.leetcode-cn.com/0c744e51c38fb09255bfd9100e3823efa1497e2f84568a5064cb032ad2ad8415-image.png)

Python中的`deque`可以对`pop(0)`，就是`popleft()`实现$O(1)$的时间复杂度。

![image.png](https://pic.leetcode-cn.com/4c73696cb31539bebd47997087229a15fd25de3718c76eb042cc861eece6fe54-image.png)

### Python完整代码

```
class MaxQueue(object):

    def __init__(self):
        from collections import deque
        self.que = deque()
        self.sort_que = deque()   

    def max_value(self):
        """
        :rtype: int
        """
        return self.sort_que[0] if self.sort_que else -1   

    def push_back(self, value):
        """
        :type value: int
        :rtype: None
        """
        self.que.append(value)
        while self.sort_que and self.sort_que[-1] < value:
            self.sort_que.pop()
        self.sort_que.append(value)
        
    def pop_front(self):
        """
        :rtype: int
        """
        if not self.que: return -1
        res = self.que.popleft()
        if res == self.sort_que[0]:
            self.sort_que.popleft()
        return res
```

溜了。

![image.png](https://pic.leetcode-cn.com/faaecaf204ad4649aa15bcd16cdd6aea2d239488f044f2becddb52dfe2972a09-image.png)

