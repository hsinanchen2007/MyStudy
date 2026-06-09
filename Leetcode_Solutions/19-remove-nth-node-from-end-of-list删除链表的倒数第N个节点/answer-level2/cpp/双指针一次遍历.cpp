### 解题思路
此处撰写解题思路

### 代码
给定两个指针分别为p,q，都指向头节点，先让q向前移动n-1个位置，然后p，q一起移动，直至q移至尾部，则此时p为需要删除的节点
特特殊情况，需要判断p是否为头节点和尾节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //给定两个指针分别为p,q，都指向头节点，先让q向前移动n-1个位置，然后p，q一起移动，直至q移至尾部
        ListNode * p = head;
        ListNode * q = head;
        ListNode * pre = head;//记录待删除前一个节点
        if(n==0)
            return head;
        //将指针q后移n-1位
        while(n-1!=0){
            q = q->next;
            n--;
        }
        //同时移动p,q直至q移到最后一个节点，并记录p的前一个节点pre
        while(q->next!=NULL){
            pre = p;
            p = p->next;
            q = q->next;
        }
        //p是头节点且存在后面的节点
        if(p==head&&head->next!=NULL){
            head = head->next;
            return head;
        }//p是头节点且p已经为最后一个节点
        else if(p==head&&head->next==NULL){
            head = NULL;
            return head;
        }//p为最后一个节点，但不是头节点
        else if(p!=head&&p->next==NULL){
            pre->next = NULL;
            return head;
        }//p是中间节点，既不是头节点也不是尾节点
        else if(p!=head&&p->next!=NULL){
            pre->next = p->next;
            return head;
        }
        else 
            return head;
    }
};
```