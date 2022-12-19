### 解题思路
1. 构造一个列表`node_list`，按顺序用来保存所有节点；假设有5个节点，则`node_list=[node0,node1,node2,node3,node4]`;
2. 之后的关键是如何将`node_list`进行重排；根据题意，奇数位为从前往后的节点顺序，偶数位为从后向前的节点顺序；令`index`为`node_list_arranged=[node0,node4,node1,node3,node2]`重排后节点在原`node_list`中的下标；则`index=[0,4,1,3,2]`; 如何构造`index`, 令`index1=[0,1,2,3,4], index2=[4,3,2,1,0], index=[]`，每次循环依次从`index1, index2`中取一个数，直至`len(index)=5`为至。再按照`index`中的下标顺序重排`node_list`从而重排链表；


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not (head and head.next and head.next.next):
            return
        
        tmp = head
        # 按顺序保存链表节点，node_list[0]存入任一个节点
        node_list = [ListNode(0)]
        while tmp:
            node_list.append(tmp)
            tmp = tmp.next

        # index_list保存重排节点的下标，并在保存节点时重排链表；
        index_list, n = [0], len(node_list)
        for i in range(1, n):
            index_list.append(i)
            node_list[index_list[-2]].next = node_list[index_list[-1]]
            if len(index_list) == n:
                node_list[index_list[-1]].next = None
                break
            
            index_list.append(n-i)
            node_list[index_list[-2]].next = node_list[index_list[-1]]
            if len(index_list) == n:
                node_list[index_list[-1]].next = None
                break
        return 
        
```