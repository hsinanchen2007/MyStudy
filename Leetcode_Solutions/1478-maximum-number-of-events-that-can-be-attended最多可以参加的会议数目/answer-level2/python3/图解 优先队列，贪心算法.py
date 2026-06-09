### 1. 什么是优先队列
我们首先来回顾一下队列吧，队列是一种先进先出（FIFO）的数据结构，它的本质是一个线性表，只能在表的一端插入值，在表的另一端删除值。
- 队尾（rear）：允许插入的一端；
- 队头（front）：允许删除的一端。
![幻灯片1.JPG](https://pic.leetcode-cn.com/b625dfb997f7d1a45f3a060c4b1c90199fbea387702973e35bdd354fc12069f1-%E5%B9%BB%E7%81%AF%E7%89%871.JPG)

优先队列也是一种队列，与队列不同的是，优先队列不再遵循先入先出的原则，而是分成了两种情况：
- 最大优先队列，无论入队顺序，当前最大的元素优先出队。
- 最小优先队列，无论入队顺序，当前最小的元素优先出队。

对于最小优先队列，队列中的每个元素都有一个权值，权值小的优先出队。假如我们将自身的数值作为权值，那么最小优先队列中较小的数会排在队列的前面，当加入一个新值 `3` 时，`3` 会在队列中处于合适的位置。
![最多可以参加的会议.png](https://pic.leetcode-cn.com/9a5fe2634473a792d6644492a465905c041c156f1362624aea924958192d1991-%E6%9C%80%E5%A4%9A%E5%8F%AF%E4%BB%A5%E5%8F%82%E5%8A%A0%E7%9A%84%E4%BC%9A%E8%AE%AE.png)

当进行出队操作时，每次会从队首弹出队列中最小的元素：
![幻灯片2.PNG](https://pic.leetcode-cn.com/1f0822918ada35f96954f49b074263c9747865409c466add72ab708b8e5d9258-%E5%B9%BB%E7%81%AF%E7%89%872.PNG)

最大优先队列则与之相反，最先弹出队列中最大的元素。

事实上，优先队列的本质上是一个堆，它是一棵完全二叉树，分为小顶堆和大顶堆：
-  小顶堆是每一个根节点小于左右子节点的完全二叉树，堆顶元素最小，对应最小优先队列；
- 大顶堆是每一个根节点大于左右子节点的完全二叉树，堆顶元素最大，对应最大优先队列；

由于删除堆顶元素时的时间复杂度为 $O(logN)$，因此在优先队列中入队和出队操作的时间复杂度也是 $O(logN)$。

### 2. 解题思路

贪心思想：**为了能参加最多的会议，我们尽量每次参加开始时间最早的会议。** 注意以下问题：
1. 比如某会议时间是 `[1,10]`，那么我们先尽量尝试第 `1` 天参加，如果参加了别的会议，再尝试第 `2` 天...
2. 如果两个会议开始时间相同，我们优先选择结束时间早的那个会议。比如 `[1,4]` 和 `[1,3]`，利用优先队列，第 `1` 天先参加 `[1,3]`，第 `2` 天参加 `[1,4]`。
#### 算法：
我们将 `events` 按照最小优先队列（小顶堆）的结构来储存，当队列不为空时，弹出队首元素，
1. 判断能否参加会议，若结束时间小于当天，说明过期了不能参加，跳过；
2. 如果可以参加，比较当天和开始时间：
    - 如果当天大于开始时间，说明我们没有必要非在今天参加，把 `[当天，结束时间]`重新加入优先队列，以查找有没有只能在今天参加的会议；
    - 如果当天等于开始时间，我们立即开始这个会议。因为优先队列保证开始时间相同时结束时间是递增的。

<![幻灯片1.JPG](https://pic.leetcode-cn.com/5fec1a9bc4a4b25c51657317560e367c33347db52d787050e654b715f10908b0-%E5%B9%BB%E7%81%AF%E7%89%871.JPG),![幻灯片2.JPG](https://pic.leetcode-cn.com/24dcc6795134e49f13e81619fe33dedc3c78793e66ed9025c5d7a293b79a8bb0-%E5%B9%BB%E7%81%AF%E7%89%872.JPG),![幻灯片3.JPG](https://pic.leetcode-cn.com/683633ce0bee68d5948354c17baa77eff61666b606ee216963713da610afb00f-%E5%B9%BB%E7%81%AF%E7%89%873.JPG),![幻灯片4.JPG](https://pic.leetcode-cn.com/fb7c1cb66690ebb2eb406db95cd71c4215228605e11780ca61134559795262bb-%E5%B9%BB%E7%81%AF%E7%89%874.JPG),![幻灯片5.JPG](https://pic.leetcode-cn.com/3f22e0153cd4e5d1529495ad2d49c85319b51730fac22df6fb38744edfa1390c-%E5%B9%BB%E7%81%AF%E7%89%875.JPG),![幻灯片6.JPG](https://pic.leetcode-cn.com/c4153145efb94a055972fc5de6cc3c64b838e49daff5972e3229df83fb6d6588-%E5%B9%BB%E7%81%AF%E7%89%876.JPG),![幻灯片7.JPG](https://pic.leetcode-cn.com/e20d6ec14adea3f5e745342a2cb057a3115cc89c66706b62748315adff0a3e82-%E5%B9%BB%E7%81%AF%E7%89%877.JPG),![幻灯片8.JPG](https://pic.leetcode-cn.com/83816cf4a8a4104340abb33ba42475d360c6e40e2e4fbfd09c2b0027e5046777-%E5%B9%BB%E7%81%AF%E7%89%878.JPG),![幻灯片9.JPG](https://pic.leetcode-cn.com/5e3b0d37a8328f590f68e8ebfb4ead035ca753e2318f848cdc81e72ece4dd881-%E5%B9%BB%E7%81%AF%E7%89%879.JPG),![幻灯片10.JPG](https://pic.leetcode-cn.com/360d44ff51a9f01b3b8b57e96206fdd58a2e54d8a850797544f567585824109a-%E5%B9%BB%E7%81%AF%E7%89%8710.JPG),![幻灯片11.JPG](https://pic.leetcode-cn.com/1b47022203c363dab67d294715bba872c8335162d87f82710a94556435ee4eb7-%E5%B9%BB%E7%81%AF%E7%89%8711.JPG),![幻灯片12.JPG](https://pic.leetcode-cn.com/f243868025697227d5d4d7bbd102e410ebcfbb2a2e589888f513488f36e97e05-%E5%B9%BB%E7%81%AF%E7%89%8712.JPG)>


### 代码
```python []
class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        res = 0
        heapq.heapify(events) # 把events转化成堆结构
        cur = events[0][0]
        while events:
            s, e = heapq.heappop(events)
            # print([s,e])
            if e < cur: # 如果结束时间小于当前天，说明过期了，不能参加
                continue
            # 如果开始时间小于当天，我们也不必今天参加，可以在（当天，结束天）任何一天参加
            if s < cur: 
                heapq.heappush(events,[cur,e])
            else:
                cur = max(cur + 1,s + 1)
                res += 1
        return res 
```