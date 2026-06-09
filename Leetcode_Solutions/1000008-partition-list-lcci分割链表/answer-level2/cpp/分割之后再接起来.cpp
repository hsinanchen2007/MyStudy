### 解题思路
此处撰写解题思路
按节点的值的大小将链表分成左边的小于x的部分和右边的大于等于x的部分
之后再将两部分接起来就可以。
注意处理边界情况
包括空链表和链表所有值大于等于x或小于x的情况。
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
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return head;
        ListNode *left=NULL,*right=NULL,*p;
        while(head){
            if(head->val < x){
                p=head->next;
                head->next=left;
                left=head;
                head=p;
            }else{
                p=head->next;
                head->next=right;
                right=head;
                head=p;
            }
        }
        if(!left)
            return right;
        p=left;
        while(p->next)
            p=p->next;
        p->next=right;
        return left;
    }
};
```