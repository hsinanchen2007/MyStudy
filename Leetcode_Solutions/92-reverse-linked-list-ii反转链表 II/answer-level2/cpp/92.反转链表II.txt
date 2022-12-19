### 解题思路
这道题的关键是找到逆置段的前驱和后继，找到后对需要逆置的段进行逆置，逆置完成后对链表重新进行链接
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int change_len=n-m+1;//需要反转链表的长度
        ListNode *pre_head = NULL;//逆置开始节点前驱
        ListNode *result = head;//返回结果节点
        while(head && --m)//找到逆置开始节点的前驱节点
        {
            pre_head=head;
            head = head->next;
        }
        ListNode *tail=head;
        ListNode *new_head = NULL;//找到逆置结束节点的后继节点
        while(head&&change_len)//反转链表
        {
            ListNode *next=head->next;
            head->next=new_head;
            new_head=head;
            head=next;
            change_len--;   
        }
        tail->next=head;//链接链表尾
        if(pre_head)//链接链表头
        {
            pre_head->next=new_head;
        }
        else
        {
            result=new_head;
        }
        return result;
    }
};
```