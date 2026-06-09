迭代
- 定义头结点
- 若 l1l1 指向的结点值 << l2l2 指向的结点值，则将 l1l1 链接到头结点的 nextnext 位置
- 否则将 l2l2 链接到头结点的 nextnext 位置
- 循环进行，直至 l1l1 或 l2l2 为 NULLNULL
- 最后，将 l1l1 或 l2l2 中剩下的部分，链接到头结点后面

代码
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                dummy->next = l1;
                l1 = l1->next;
            }else{
                dummy->next = l2;
                l2 = l2->next;
            }
            dummy = dummy->next;
        }
        dummy->next = l1 == NULL ? l2 : l1;
        return head->next;
    }
};
```
