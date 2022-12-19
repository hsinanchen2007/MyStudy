### 解题思路
这道题需要品味的地方在于，我们虽然看似开了两个子链表，但实际上是O(1)的空间复杂度，因为我们从头到尾都在对指针进行操作。

### 代码

```cpp
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* smaller = new ListNode(0);
        ListNode* bigger = new ListNode(0);
        ListNode* ptr1 = smaller;
        ListNode* ptr2 = bigger;
        while (head != NULL) {
            if (head->val >= x) {
                ptr2->next=head;
                ptr2 = ptr2->next;
            }
            else {
                ptr1->next=head;
                ptr1 = ptr1->next;                
            }
            head = head->next;
        }
        //这一步非常非常关键，避免了环形链表的产生！！！需要理解我们上述的操作都是在针对指针操作，
        //其本质就是改变链表中节点的next元素，并没有额外产生新的节点。
        //所以自然而然的，我们新的链表尾部节点的next就需要更新为NULL，否则它会指向原链表中某个未知节点形成环形链表！
        ptr2->next = NULL;
        //把两个子集连起来
        ptr1->next = bigger->next;
        return smaller->next;
    }
};
```