### 解题思路
用Python对BFS方法的实现

### 代码

```python3
class Solution:
	def shortestPathLength(self, graph: List[List[int]]) -> int:
		final_target = (1<<len(graph))-1
		node_masks = [1<<i for i in range(len(graph))]
		visited_states = [{node_masks[i]} for i in range(len(graph))]
		queue = [(i, node_masks[i]) for i in range(len(graph))]
		steps = 0
		while queue:
			curr_count = len(queue)
			while curr_count:
				curr_node, curr_state = queue.pop(0)
				if curr_state == final_target:
					return steps
				for neibor_node in graph[curr_node]:
					new_state = curr_state | node_masks[neibor_node]
					if new_state == final_target:
						return steps + 1
					if new_state not in visited_states[neibor_node]:
						visited_states[neibor_node].add(new_state)
						queue.append((neibor_node, new_state))
				curr_count -= 1
			steps += 1
		return -1

```