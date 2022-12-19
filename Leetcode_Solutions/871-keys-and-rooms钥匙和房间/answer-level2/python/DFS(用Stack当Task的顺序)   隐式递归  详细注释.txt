### 解题思路
	详细注释：上方
	超简洁注释：代码注释

### 代码

```python
# 深度优先搜索

'''
·题目思路：
    1.迷宫类，起始点？(BFS/DFS？初始化是0还是特定内部点？图遍历还是纯数据关系？)
    2.从起始点出发，如何进入与起始点相关联的地区？(层级逻辑关系)
    3.如何标记已经到达的地区/房间？递归结束条件？(数组door[]存储True/False:校验是否来过)
    4.如何进入下一层/级的递归？(Queue/Stack：保存当前任务位置+记录后面任务)


·算法：
    1.初始化所有房door[all]=False
    2.初始化第一个房door[0]为True(可开启)
    3.初始化'任务列表Stack',并且将第一房间作为Stack的唯1元素(PS:总结小技巧，任务执行往往与Queue和Stack有关,而如果要'层级任务',即底层->复杂的高层,往往使用1个element的Stack进行‘隐式递归’处理。)

    4.利用while stack作为'递归入口',nei = stack.pop()和stack.append(nei)作为递归的'动力机制';
    5.通过if not door[nei]	和 door[nei] = True ,将False元素进行True登记,防止重复递归

'''

class Solution(object):
	def canVisitAllRooms(self,rooms):
		door = [False] * len(rooms) # 初始化所有房间为False
		door[0] = True	# 初始化第一个房间为True
		stack = [0] # 初始化Task,即开局有index=？的钥匙

		# while we have a '0' key in stack..
		while stack: 
			node = stack.pop() # get the next Task(key to open Door)

			for nei in rooms[node]: 
				if not	door[nei]: # key hasn't been used yet
					door[nei] = True # mark
					stack.append(nei) # add next Task

		return all(door)
		# Return True if we've visited every rooms.

	
'''
复杂度分析：
	· 时间复杂度：O(N+E),其中N是房间数量,E是钥匙数量
	· 空间复杂度：O(N),用来存储Stack door
'''
```