### 解题思路
新手上路---使用迭代的方式
使用双指针的方式进行迭代，定义两个指针pre和cur，cur先指向head，然后不断遍历cur。

在遍历的过程中将 cur 的 next 指向 pre，用一个中间的变量来存储原来的指向，然后 pre 和 cur 往后进一位。

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* pre=NULL;
        ListNode* cur=head;
        while(cur)
        {
            ListNode* temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        return pre;
    }
};

执行用时 :8 ms, 在所有 C++ 提交中击败了78.19%的用户

内存消耗 :10.2 MB, 在所有 C++ 提交中击败了5.00%的用户
```python
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return 
        pre=None
        cur=head
        while cur:
            #中间变量temp存储当前节点的下一节点
            temp=cur.next
            cur.next=pre
            #pre和cur往后移动一位
            pre=cur
            cur=temp
        return pre
```
执行用时 :40 ms, 在所有 Python3 提交中击败了65.15%的用户

内存消耗 :14.4 MB, 在所有 Python3 提交中击败了47.81%的用户