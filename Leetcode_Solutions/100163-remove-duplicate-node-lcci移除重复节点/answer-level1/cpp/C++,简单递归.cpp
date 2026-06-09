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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;//设置好递归停止条件
        head->next=removeDuplicateNodes(head->next);
        //不需要想递归里面做了什么
        //此时返回的已经是一个没有重复值的链表了
        //现在唯一要考虑的就是返回的链表中可能存在与头节点有相同值的节点
        //这个节点最多只有一个，也可能没有
        //找到它并删除就好了
        ListNode*p1=head->next;
        ListNode*p2=head;  
        while(p1)
        {
             if(p1->val==head->val)  //找到与头结点有相同值的结点时，就删除后马上返回
            {
                p2->next=p1->next;
                delete p1;
                return head;       
            }
            else
            {
                p2=p1;
                p1=p1->next;
            }
        }
        return head;     //没有与头结点有相同值的结点时遍历整个链表后返回
    }
};
```
