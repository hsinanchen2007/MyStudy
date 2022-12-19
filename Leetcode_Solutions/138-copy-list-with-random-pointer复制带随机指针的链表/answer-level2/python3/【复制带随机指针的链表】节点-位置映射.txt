## 用字典记录下每个节点与其在链表中的位置的对应关系。
##### 需要两个字典，一个记录旧链表：old_node:index, 一个记录新链表：index：new_node.
![copy-list-with-random-pointer.png](https://pic.leetcode-cn.com/6f732976d8a0a807dce59d9429624d18d68b83c2fb75e1e804b50acd91474d23-copy-list-with-random-pointer.png)

---

### 两步走：
- ##### 1、 遍历一趟旧链表，生成新链表。在其中记录位置-节点对应关系
- ##### 2、 再遍历一趟，更新random。查字典，得到旧节点的random所在的位置，再获取新链表这个位置的新节点。
```
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if head is None:
            return None
        map_old_node2index = dict()
        map_new_index2node = dict()
        newhead = Node(head.val)
        p_new = newhead
        p_old = head.next
        i = 0
        map_old_node2index[head] = i
        map_new_index2node[i] = newhead
        #：复制所有节点，并记录每个节点与其index（在链表第几个）的对应关系
        while p_old:
            i += 1
            p_new.next = Node(p_old.val)
            p_new = p_new.next
            map_new_index2node[i] = p_new
            map_old_node2index[p_old] = i
            p_old = p_old.next
            
        p_new = newhead
        p_old = head
        #：修改random指针
        while p_old:
            if p_old.random is p_old:
                p_new.random = p_new
            elif p_old.random is None:
                p_new.random = None
            else:
                #： oldnode.random--> index --> newnode
                #： p_old.random得到旧节点random指针指向的旧节点
                #： map_old_node2index[p_old.random] 得到 这个节点所在index
                #： 根据这个index找到对应新节点
                p_new.random = map_new_index2node[map_old_node2index[p_old.random]]

            p_new = p_new.next
            p_old = p_old.next

        return newhead



            
```

##### 时间复杂度 O（n）,需要遍历两遍；空间复杂度O(n)，两个字典2*n个键值对。