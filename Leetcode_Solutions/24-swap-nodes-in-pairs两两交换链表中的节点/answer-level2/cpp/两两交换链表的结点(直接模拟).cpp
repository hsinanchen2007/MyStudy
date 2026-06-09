详见代码，自己在纸上画下应该很好理解
因为链表考研还是可能靠算法题的，特意刷一下

### 代码

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //链表的题目最好有头节点，自己造一个，方便操作
        //直接模拟，修改指针的指向，即可
        ListNode* new_head = new ListNode();
        ListNode* pre = new_head;
        new_head->next = head;
        while(head && head -> next){
            ListNode* A = head;
            ListNode* B = head->next;
            A->next = B->next;
            B->next=A;
            pre->next=B;
            pre=A;   
            head=A->next;
        }
        return new_head->next;
    }
};
```