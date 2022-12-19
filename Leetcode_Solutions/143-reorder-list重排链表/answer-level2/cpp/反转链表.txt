### 解题思路
此处撰写解题思路

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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return ;
        // 找到中间节点
        ListNode* pre = head->next;
        ListNode* last = head;
        while(pre != NULL && pre->next != NULL){
            pre = pre->next->next;
            last = last->next;
        }
        // 反转链表
        pre = last->next;
        ListNode* cur = NULL;
        ListNode* tmp;
        while(pre != NULL){
            tmp = pre;
            pre = pre->next;
            tmp->next = cur;
            cur = tmp;
        }
        // head = cur;
        // 插入
        ListNode* p = head;
        ListNode* q = cur;
        ListNode* rt = head;
        while(q != NULL){
            p = p->next;
            rt->next = q;
            q = q->next;
            rt->next->next = p;
            rt = p;
        }
        if(p != NULL) rt->next = NULL;
    }
};
```