### 解题思路
1)通过取余得到真实的旋转元素个数r_l；
2）本质上是将链表最后的r_l个元素整体移到头部，用两个相隔r_l的指针遍历一遍即可；

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
    ListNode* rotateRight(ListNode* head, int k) {
        int l=0;
        ListNode *p = head;
        ListNode *q = head;
        if(head==NULL) return head;
        while(p!=NULL){
            l++;
            p=p->next;
        } 
        int r_l = k%l;
        p = head;
        for(int i=0;i<r_l;++i) p=p->next;
        while(p->next!=NULL){
            p=p->next;
            q=q->next;
        }
        p->next=head;
        head = q->next;
        q->next = NULL;
        return head;
    }
};
```