### 解题思路
增加哑结点，解决删除第一个元素的问题，遍历链表找到删除元素之前的结点。

有个疑问？在执行删除操作时，被删除的结点是否需要释放？

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pre=new ListNode(0);
        pre->next=head;
        ListNode *p=pre;
        while(p->next)
        {
            if(p->next->val==val)       
                p->next=p->next->next;             
            else
                p=p->next;
        }
        return pre->next;
    }
};
```