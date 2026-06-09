####  方法：哨兵节点
如果删除的节点是中间的节点，则问题似乎非常简单：
- 选择要删除节点的前一个结点 `prev`。
- 将 `prev` 的 `next` 设置为要删除结点的 `next`。

![在这里插入图片描述](https://pic.leetcode-cn.com/30d0d710628666a95ffbc21bf2f24c51fb7da094df2901fc87282040d80b3a64-file_1578026286309){:width=400}

当要删除的一个或多个节点位于链表的头部时，事情会变得复杂。

![在这里插入图片描述](https://pic.leetcode-cn.com/eac60c97d17a38b82d0092a1f39d4cae2441ea06d98c0d8d420cccd8cdd3d8e2-file_1578026286054){:width=400}
{:align=center}

可以通过哨兵节点去解决它，哨兵节点广泛应用于树和链表中，如伪头、伪尾、标记等，它们是纯功能的，通常不保存任何数据，其主要目的是使链表标准化，如使链表永不为空、永不无头、简化插入和删除。

![在这里插入图片描述](https://pic.leetcode-cn.com/c650a78cb34caf9a00469651abfc14181c474e2c6152e87273092e7dfd331f19-file_1578026286317){:width=400}

在这里哨兵节点将被用于伪头。

**算法：**
- 初始化哨兵节点为 `ListNode(0)` 且设置 `sentinel.next = head`。
- 初始化两个指针 `curr` 和 `prev` 指向当前节点和前继节点。
- 当 `curr != nullptr`：
	- 比较当前节点和要删除的节点：
		- 若当前节点就是要删除的节点：则 `prev.next = curr.next`。
		- 否则设 `prve = curr`。
	- 遍历下一个元素：`curr = curr.next`。
- 返回 `sentinel.next`。    
 
```python [solution1-Python]
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        sentinel = ListNode(0)
        sentinel.next = head
        
        prev, curr = sentinel, head
        while curr:
            if curr.val == val:
                prev.next = curr.next
            else:
                prev = curr
            curr = curr.next
        
        return sentinel.next
```

```java [solution1-Java]
class Solution {
  public ListNode removeElements(ListNode head, int val) {
    ListNode sentinel = new ListNode(0);
    sentinel.next = head;

    ListNode prev = sentinel, curr = head;
    while (curr != null) {
      if (curr.val == val) prev.next = curr.next;
      else prev = curr;
      curr = curr.next;
    }
    return sentinel.next;
  }
}
```

```c++ [solution1-C++]
class Solution {
  public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* sentinel = new ListNode(0);
    sentinel->next = head;

    ListNode *prev = sentinel, *curr = head, *toDelete = nullptr;
    while (curr != nullptr) {
      if (curr->val == val) {
        prev->next = curr->next;
        toDelete = curr;
      } else prev = curr;

      curr = curr->next;

      if (toDelete != nullptr) {
        delete toDelete;
        toDelete = nullptr;
      }
    }

    ListNode *ret = sentinel->next;
    delete sentinel;
    return ret;
  }
};
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N)$，只遍历了一次。
* 空间复杂度：$\mathcal{O}(1)$。