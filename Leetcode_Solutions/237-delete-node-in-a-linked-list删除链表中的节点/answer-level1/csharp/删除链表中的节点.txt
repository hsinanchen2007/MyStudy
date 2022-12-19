**思路：** 这道题没啥子思路，别先入为主就好。别一上来看到题目就以为是删除某个值的节点。认真审题才最重要！！！
```
public void DeleteNode(ListNode node)
        {
            node.val = node.next.val;
            node.next = node.next.next;
        }
```
