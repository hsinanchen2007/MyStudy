思路：广度优先搜索
1. 将房间抽象为节点，1号房间能进入2号房间表明节点1和节点2有边，即连通。
2. 所以从0号节点开始，将已经访问的节点放到set中，查找迅速；待访问的节点放到队列中。
3. 直接有列表模拟队列即可，python提供的队列因为考虑到线程安全的问题，所以效率比较低。
4. 时间：52ms，内存：13.4MB

## python3代码
```
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        q= [0] #队列，存放待访问节点
        s = {0} #存放已经访问的节点
        while len(q) != 0:
            node = q.pop(0) #出栈代表已经被访问过
            for i in rooms[node]:
                if i not in s:
                    q.append(i)
                    s.add(i)

        return len(s) == len(rooms)
```