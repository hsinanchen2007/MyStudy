### 解题思路
作为一个新手，我看到题目也是一脸懵，因为 Python 在不引入第三方包的前提下是没有队列的，只有 List，题干其实也没有写明白在 Python 环境中可以使用哪些函数或者属性。

现在结合对于队列的复习梳理一下可以使用哪些 List 的特性：
* len(L) 获取长度，这个严格意义上不能用，不过自己写一个self.size，在每一次pop() push() 操作之后更新一下也不难。（我有点懒就用了，也没有判我错，我也就懒得改了(^_^)v）
* L[0] 获取第一个元素 -> 'a' ，这个就算是队列的特性了，**「先进先出」**，在实现阶段就是队尾进入队头出，那么我们可以使用该特性，并且仅可使用 L[0]，获取其他元素都算是不合题意
* L.append('d') 在队列后追加元素，同上理「队尾进」就可以使用这一条
* L.insert(1, 'a2') 把元素插入到指定位置，除非是插入队尾，否则该特性不能使用
* L.pop() 删除列表末尾元素，队列只能删除队头的元素，该特性不可使用
* L.pop(0） 删除第一个元素，可以使用该特性，但是仅可以删除第一个元素
* L[1] = 'x' 替换元素，队列和栈都不能替换元素
* L = [] 空的列表，可以用于初始化

### 代码

```py
class MyStack(object):

    def __init__(self):
        # 初始化
        self.mainQueue = []
        self.assistQueue = []

    def push(self, x):
        #将新元素放在辅助队列的队首
        self.assistQueue.append(x)
        #让mainQueue中的所有元素通过pop的方式被吐出来，然后放入assistQueue的队尾
        while len(self.mainQueue) != 0:
            self.assistQueue.append(self.mainQueue.pop(0))
        #现在assistQueue是完整的队列了，现在交换两个队列的名字，方便之后使用
        self.mainQueue = self.assistQueue
        self.assistQueue = []

    def pop(self):
        #吐出第一个元素
        return self.mainQueue.pop(0)

    def top(self):
        #读取第一个元素
        return self.mainQueue[0]

    def empty(self):
        #使用len()判断队列是否为空
        if len(self.mainQueue) == 0:
            return True
        else:
            return False
```
第一天打卡，若有任何错误，还请指正。