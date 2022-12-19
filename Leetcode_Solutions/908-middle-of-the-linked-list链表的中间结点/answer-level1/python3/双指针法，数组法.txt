### 解题思路
双指针法，一个记录中间节点，一个记录当前遍历节点。
中间节点索引：middle_index = (1 + index // 2)，如果索引发生变化，说明中间节点后移。middle_node = middle_node.next
上面步骤直到链表遍历完毕。

### 代码

```python3
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        tmp = head
        middle_node = head
        index = 1
        middle_index = index
        while tmp:
            new_middle_index = (1 + index // 2)
            if new_middle_index != middle_index:
                middle_index = new_middle_index
                middle_node = middle_node.next
            index = index + 1
            tmp = tmp.next
        return middle_node
```

### 解题思路
数组法，将链表中的元素保存到数组中。计算出数组长度，然后直接返回数组的中间节点。
### 代码
```python3
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        tmp = head
        index = 0
        node_list = list()
        while tmp:
            node_list.append(tmp)
            index = index + 1
            tmp = tmp.next
        index = index - 1
        middle_index = (index // 2) + (index % 2)
        #print(middle_index)
        return node_list[middle_index]
```