### 解题思路
此处撰写解题思路
寻找倒数第k个节点的值，这里首先让第一个指针走k步
之后两个指针同步走，当第一个指针到达末尾时，第二指针所指就是倒数第k个元素。
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
    int kthToLast(ListNode* head, int k) {
        ListNode *p=head;
        while(k--)
            head=head->next;
        while(head){
            p=p->next;
            head=head->next;
        }
        return p->val;
    }
};
```