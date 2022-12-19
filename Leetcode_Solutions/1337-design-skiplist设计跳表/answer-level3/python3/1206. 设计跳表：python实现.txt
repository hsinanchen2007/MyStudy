概率分层直接进行了一个随机数的对数计算，其他的跟传统跳表实现起来大同小异。

用的是纯跳表单元，只有值、向右、向下三个属性，没有使用数组存表，`add`的时候用一个`prev`数组记录前一个跳跃点，所以不需要在结构体里用超过两个方向的形式存储，空间上比数组存表略优一点吧。

用统计字典`collections.defaultdict(int)`或者桶数组`[0] * 20000`来提交这题当然很快，大约100ms+这样，这些数据结构的底层都是封装在c扩展里的，纯python写的跳表比前者慢这么多很正常，我这个代码也不例外，大约300ms+这样，最多不超过500ms，其他python代码超时肯定是哪里写错了，大概率是跳跃的时候没有跳出循环。

（注：标签2有注释版本）

```python []
maxLevel = 16
power = 2
maxRand = power ** maxLevel - 1
randLevel = lambda: maxLevel - int(math.log(random.randint(1, maxRand), power))

class SkipNode:
    def __init__(self, value):
        self.value = value
        self.right = None
        self.down = None

class Skiplist:
    def __init__(self):
        left = [SkipNode(-float('inf')) for _ in range(maxLevel)]
        right = [SkipNode(float('inf')) for _ in range(maxLevel)]
        for i in range(maxLevel - 1):
            left[i].right = right[i]
            left[i].down = left[i + 1]
            right[i].down = right[i + 1]
        left[-1].right = right[-1]
        self.head = left[0]

    def search(self, target: int) -> bool:
        node = self.head
        while node:
            if node.right.value > target:
                node = node.down
            elif node.right.value < target:
                node = node.right
            else:
                return True

    def add(self, num: int) -> None:
        prev = []
        node = self.head
        while node:
            if node.right.value >= num:
                prev.append(node)
                node = node.down
            else:
                node = node.right
        arr = [SkipNode(num) for _ in range(randLevel())]
        t = SkipNode(None)
        for p, a in zip(prev[maxLevel - len(arr): ], arr):
            a.right = p.right
            p.right = a
            t.down = a
            t = a

    def erase(self, num: int) -> bool:
        ans = False
        node = self.head
        while node:
            if node.right.value > num:
                node = node.down
            elif node.right.value < num:
                node = node.right
            else:
                ans = True
                node.right = node.right.right
                node = node.down
        return ans
```
```python []
# 最大级深maxLevl=16，power=2分链表，随机数的上限maxRand
maxLevel = 16
power = 2
maxRand = power ** maxLevel - 1
# 随机函数，这里就相当于[1 ... 65535]取随机，然后再对2取对数，可保证插入深度在[1 ... 16]这些数字里呈指数分布
randLevel = lambda: maxLevel - int(math.log(random.randint(1, maxRand), power))

# 三个属性，跳表本体的值，向右的指针，向下的指针
class SkipNode:
    def __init__(self, value):
        self.value = value
        self.right = None
        self.down = None

class Skiplist:
    def __init__(self):
        # 初始化左右正负无穷墙壁
        left = [SkipNode(-float('inf')) for _ in range(maxLevel)]
        right = [SkipNode(float('inf')) for _ in range(maxLevel)]
        # 把墙壁交联在一起
        for i in range(maxLevel - 1):
            left[i].right = right[i]
            left[i].down = left[i + 1]
            right[i].down = right[i + 1]
        # 最后一层单独处理，只有向右指向，没有向下指向
        left[-1].right = right[-1]
        # 跳表初始指针为左壁的首元素
        self.head = left[0]

    def search(self, target: int) -> bool:
        # 从初始指针开始进行跳跃迭代，找不到的node迟早为None，跳出循环自动返回None，线上测试和False等价
        node = self.head
        while node:
            if node.right.value > target:
                node = node.down
            elif node.right.value < target:
                node = node.right
            else:
                return True

    def add(self, num: int) -> None:
        # 用prev数组存储往下跳跃前的跳表指针，方便之后插入指针时前后交联，免去双向指针处理
        prev = []
        # 原理依旧是指针迭代
        node = self.head
        while node:
            # 碰到右边大于等于自己时就往下跳，帮助prev生成完整的指针数组
            if node.right.value >= num:
                prev.append(node)
                node = node.down
            else:
                node = node.right
        # 待插入的指针数组，长度按概率进行随机
        arr = [SkipNode(num) for _ in range(randLevel())]
        # 用zip把prev后续的元素与新的指针数组交联在一次即可完成跳表插入
        t = SkipNode(None)
        for p, a in zip(prev[maxLevel - len(arr): ], arr):
            a.right = p.right
            p.right = a
            t.down = a
            t = a

    def erase(self, num: int) -> bool:
        # ans为输出标志，erase的结构和search结构类似，依旧是指针迭代
        ans = False
        node = self.head
        while node:
            if node.right.value > num:
                node = node.down
            elif node.right.value < num:
                node = node.right
            else:
                # 存在相等时就修改输出标志
                ans = True
                # 删除node.right的在跳表中的关系
                node.right = node.right.right
                node = node.down
        return ans
```
```python []
# 可以快速AC的方法，不要学
class Skiplist:
    def __init__(self):
        self.d = [0] * 20000
        # self.d = collections.defaultdict(int)

    def search(self, target: int) -> bool:
        return self.d[target]

    def add(self, num: int) -> None:
        self.d[num] += 1

    def erase(self, num: int) -> bool:
        if self.d[num]:
            self.d[num] -= 1
            return True
```
