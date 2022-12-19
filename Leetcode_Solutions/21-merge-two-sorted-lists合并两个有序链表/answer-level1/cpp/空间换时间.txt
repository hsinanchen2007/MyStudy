### 解题思路
这里用了空间换时间的方法,另一个版本内存占用较小但是 超时了。
    ListNode *p;
    ListNode *q;
    ListNode *head;
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    if(l1->val<l2->val){
        p = l1;
        q = l2;
    }else{
        p = l2;
        q = l1;
    }
    head = p;
    while(q!=NULL){
        if(p->next!=NULL){
            if(p->next->val<=q->val){
                p = p->next;
            }else{
                ListNode *temp = new ListNode(q->val);
                temp->next = p->next;
                p->next = temp; // 插入
                p = p->next;  // p指向新插入的节点
                q = q->next;
            }
        }else{
            p->next = q;
            p = p->next;
            q = q->next;
        }
    }
    return head;
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p;
        ListNode *q;
        ListNode *newNode = new ListNode(0);
        newNode->next = NULL;
        ListNode *head = newNode;
        p = l1;
        q = l2;
        while(q!=NULL&&p!=NULL){
            ListNode *node;
            if(p->val<=q->val){
                node = new ListNode(p->val);
                newNode->next = node;
                newNode = node;
                p = p->next;
            }else{
                node = new ListNode(q->val);
                newNode->next = node;
                newNode = node;
                q = q->next;
            }
        }
        while(p!=NULL){
            ListNode *pNode = new ListNode(p->val);
            newNode->next = pNode;
            newNode = pNode;
            p = p->next;
        }
        while(q!=NULL){
            ListNode *qNode = new ListNode(q->val);
            newNode->next = qNode;
            newNode = qNode;
            q = q->next;
        }
        return head->next;
    }
};
```