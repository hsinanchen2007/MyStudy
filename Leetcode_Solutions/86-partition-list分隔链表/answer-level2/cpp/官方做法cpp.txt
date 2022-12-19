1.两个链表存储，合并？  写的时候申请了空间。
2.其实并不需要 多申请空间。 穿针引线即可。 只有结点new过之后，cur就可以穿针引线了。

链表记得尾部结点 置为NULL。 很多时候构造函数帮我们做的，但是修改结点的时候可没有。

```
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
    ListNode* partition(ListNode* head, int x) {
        // 两个链表存储，合并？  写的时候申请了空间。
        // 其实并不需要 多申请空间。 穿针引线即可。 只有结点new过之后，cur就可以穿针引线了。

        // 链表记得尾部结点 置为NULL。 很多时候构造函数帮我们做的，但是修改结点的时候可没有。

        ListNode* l1 = new ListNode(0);
        ListNode* l2 = new ListNode(0);

        ListNode* c1 = l1;
        ListNode* c2 = l2;

        while(head != NULL){
            if(head->val < x){
                
                c1->next = head;
                c1 = c1->next;
            }else{
                c2->next = head;
                c2 = c2->next;
            }
            head = head->next; 
        }
        c2->next = NULL; // 关键步骤。 
        c1->next = l2->next;
        return l1->next;
    }
};
```
