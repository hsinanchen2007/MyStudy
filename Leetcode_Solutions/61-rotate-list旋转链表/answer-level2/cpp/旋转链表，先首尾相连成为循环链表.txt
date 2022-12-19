### 解题思路
先遍历到尾节点，将尾节点连接到头结点，成为循环链表，并记录链表长度len，鉴于k可能大于len，故k%=len
旋转k个节点意味着把后k个点放到前面，其实只要将头指针向前移动len-k步即可，记得最后要把头结点和尾节点断开


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
        if(!head) return NULL;
        int len = 1;
        ListNode* p = head;
        while(p->next){
            ++len;
            p = p->next;
        }
        p->next = head;
        k %= len;
        int r = len - k;
        while(r){
            head = head->next;
            p = p->next;
            --r;
        }
        p->next = NULL;
        return head;
    }
};
```