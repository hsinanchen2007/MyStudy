# 解题思路
1.初始化并查集;
2.遍历并查集中的key,当key在集合中找到了key+1的key，那么将当前元素并入并查集中;
3.返回最大集合长度。
# 代码
```python3
from collections import defaultdict
class Solution:
    def longestConsecutive(self, nums: list) -> int:
        if len(nums) == 0:
            return 0
        node = defaultdict(int)
        node_size = defaultdict(int)
        for num in nums:
            node[num] = '#'
            node_size[num] = 1

        def find_father(a):
            if node[a] == '#':
                return a
            a = find_father(node[a])
            return a

        def union(a, b):
            father_node_a = find_father(a)
            father_node_b = find_father(b)

            if father_node_a != father_node_b:
                if node_size[father_node_a] >= node_size[father_node_b]:
                    node[father_node_b] = father_node_a
                    node_size[father_node_a] += node_size[father_node_b]
                else:
                    node[father_node_a] = father_node_b
                    node_size[father_node_b] += node_size[father_node_a]

        for num in node.keys():
            if num + 1 in node.keys():
                union(num, num + 1)
        return max(node_size.values())
```
