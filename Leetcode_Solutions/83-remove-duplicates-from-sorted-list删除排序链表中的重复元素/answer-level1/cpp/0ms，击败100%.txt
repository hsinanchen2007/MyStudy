### 解题思路
当链表为空时直接返回head
定义两个指针，指向相邻两个结点，判断两个节点的值是否相等，若相等则删除后一个结点
否则两指针同时向后移一位

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode *pre = head;
        ListNode *p=head->next;
        while(p){
            if (pre->val==p->val){
                pre->next = p->next;
                p=pre->next;
            }
            else{
            pre->next = p;
            pre=pre->next;
            p=p->next;
        }}
        return head;
    }
};
```