### 解题思路
##### Python按位运算
>python按位运算是把数字看作二进制来进行计算的
`|`在python中是指或运算
`<<`:左边的数字（二进制）左移多少位
`>>`:左边的数字（二进制）右移多少位
##### 这道题也是奇怪，自己实现的或预算超时了

##### 下面进入正题，先看图：

![image.png](https://pic.leetcode-cn.com/f4463a5950282ccc8e1af5003feb691a31ab1c8c3f421d357d5dd1952a197a9a-image.png)



**这道题是属于图的题目，而且求最短路径，那么肯定是BFS**
涉及到图，我们肯定是需要设置visited的，那么这里的visited里面是放每次访问的节点吗？但是题目要求
`也可以多次重访节点，并且可以重用边`，所有这里很显然visited中不是存放每次访问的节，那么在想想，我们每次到某个节点，但是这个节点之前访问过（因为可以重复使用），但是此时的路径不同，那么还是可以入队的, 图中有文字说明！
那么如何判断路径相同呢？使用位预算，只要访问过就置为1，所以使用位运算，所以visited中存放的是每次访问到固定节点的时候的状态，如果状态相同说明就是相同的路径，不必要入队！！

### 代码

```python3
class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        if graph == [[]]:return 0
        temp = '0' * len(graph)
        states = {i: 1 << i for i in range(len(graph))} 

        print(states)
        queue = [(i, states[i]) for i in range(len(graph))]
        print(queue)
        # 这个visited的目的是记录一下，如果每次遍历到某个固定点的的状态
        visited = {i:[states[i]] for i in range(len(graph))}
        path = 0
        print(visited)
        while queue:
            n = len(queue)
            path += 1
            for _ in range(n):
                i, cur_state = queue.pop(0)
                for neighbor in graph[i]:
                    neighbor_state = cur_state | states[neighbor]
                   
                    if neighbor_state == (1<<len(graph)) -1:
                        return path

                    if neighbor_state not in visited[neighbor]:
                        visited[neighbor].append(neighbor_state)
                        queue.append((neighbor, neighbor_state))
        return -1    

```